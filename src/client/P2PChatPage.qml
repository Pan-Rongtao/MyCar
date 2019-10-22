import QtQuick 2.0
import QtQuick.Controls 2.0
import UIT.Type 1.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    MouseArea{
        anchors.fill: parent
        onPressed: kb.visible = false
    }

    signal leaveChat()
    property int itemWidth: root.width * 0.24
    property int itemHeight: root.height * 0.1

    Column{
        id:main
        width: parent.width
        height: parent.height
        spacing: height * 0.015
        Text {
            id:title
            text: P2PChat.friendNickname
            width: parent.width
            height: root.height * 0.1
            font.pointSize: height * 1 / 3
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        ListView{
            id:list
            width: parent.width; height: parent.height - title.height - tool.height - parent.spacing * 2
            model: P2PChat
            delegate: ChatItemComponent{
                width: parent.width
            }
            onCountChanged: list.positionViewAtEnd()
        }
        Row{
            id:tool
            width:parent.width;height: itemHeight
            TextField{
                id:txtMsg
                width:parent.width-btnSend.width;height: parent.height
                Keys.onReturnPressed: send()
                onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible=true
            }
            Button{
                id:btnSend
                text:"发送"
                font.bold: true;font.pixelSize: height * 0.4
                width:itemWidth;height: parent.height
                onClicked: send()
            }
        }

    }

    function send()
    {
        if(txtMsg.text === "")  return
        P2PChat.sendMessage(txtMsg.text)
        txtMsg.clear()
        txtMsg.focus = true
    }


    Component.onCompleted:{
        P2PChat.update()
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
