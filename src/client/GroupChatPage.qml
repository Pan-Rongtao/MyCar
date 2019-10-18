import QtQuick 2.0
import QtQuick.Controls 2.0
import UIT.Type 1.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    property int item0Width: 20
    signal leaveChat()

    Column{
        id:main
        width: parent.width
        height: parent.height
        spacing: 30
        Row{
            width: parent.width;height: 80
            Item{ width: item0Width;height: parent.height;  }
            Rectangle{
                id:head
                width: parent.width - add.width - item0Width;height: parent.height
                Text {
                    id:title
                    text: GroupChat.groupName
                    width: parent.width;height: parent.height
                    font.pixelSize: 26; font.bold: true
                    horizontalAlignment: Text.AlignHCenter;verticalAlignment: Text.AlignVCenter
                }
            }

            Button{ id:add; width: 30;height:width;
                Image{width: parent.width;height: parent.height; source: "images/option.png"}
                onClicked: LayerManager.switchPop(LayerManager.currentPop == Type.Pop_GroupInfo ? Type.Pop_None : Type.Pop_GroupInfo)
            }
        }


        ListView{
            id:list
            width: parent.width; height: parent.height - title.height - tool.height - parent.spacing * 2
            anchors.leftMargin: 10;anchors.rightMargin: anchors.leftMargin
            anchors.topMargin: 180;anchors.bottomMargin: anchors.topMargin
            model: GroupChat
            delegate: ChatItemComponent{
                width: parent.width
            }
            MouseArea{
                anchors.fill: parent
                onPressed: kb.visible = false
            }
            onCountChanged: list.positionViewAtEnd()
        }
        Row{
            id:tool
            width:parent.width;height: 50
            TextField{
                id:txtMsg
                width:parent.width-btnSend.width;height: parent.height
                Keys.onReturnPressed: send()
                onPressed: if(Proxy.terminalType != Type.Terminal_PC) kb.visible=true
            }
            Button{
                id:btnSend
                text:"发送"
                font.bold: true;font.pixelSize: 24
                width:80;height: parent.height
                onClicked: send()
            }
        }

    }

    function send()
    {
        if(txtMsg.text === "")  return
        GroupChat.sendMessage(txtMsg.text)
        txtMsg.clear()
        txtMsg.focus = true
    }

    Component.onCompleted:{
        GroupChat.update()
        list.positionViewAtEnd()
        txtMsg.focus = true
    }

    Keyboard{
        id:kb
        visible: false
        width: parent.width
        height: parent.height * 2 / 5
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        onVisibleChanged: {
            if(visible)
                main.height -= height
            else
                main.height += height
            list.positionViewAtEnd()
        }
        onKey: {
            if(txtMsg.focus)
                txtMsg.text += content
        }
        onDel: {
            if(txtMsg.focus)
                txtMsg.text = txtMsg.text.substring(0, txtMsg.text.length - 1)
        }
    }
}
