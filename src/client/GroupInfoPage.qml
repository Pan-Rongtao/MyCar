import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2
import UIT.Type 1.0

Rectangle {
    anchors.fill: parent

    signal finished()
    property int item0Width: 100
    property int item2Width: 80
    property int item0Height: 30

    Image{
        anchors.fill: parent
        source: "images/list_bg.png"
    }

    Column{
        anchors.fill: parent
        Grid{
            id:layout
            rows:7
            columns: 3
            width: parent.width
            height: parent.height
            rowSpacing: 30
            columnSpacing: 0
            padding: 10

            Text{ text: "群组名"; width: item0Width; font.bold: true; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{id:name; width: parent.width - item0Width - item2Width; height: item0Height; text: GroupChat.groupName; onPressed: if(Proxy.terminalType != Type.Terminal_PC) kb.visible=true}
            Button{ width: 30;height:item0Height ; onClicked: GroupChat.modifyGroupName(name.text); Image{width: parent.width;height: parent.height; source: "images/notes.png"} }


        }
        GridView{
            id:grid
            anchors.fill: parent
            anchors.leftMargin: 30;anchors.rightMargin: anchors.leftMargin
            anchors.topMargin: 100;anchors.bottomMargin: anchors.topMargin
            cellWidth: 60
            cellHeight: cellWidth
            model: GroupMembers
            delegate: Rectangle
            {
                width:grid.cellWidth
                height:grid.cellHeight
                color: mouse.pressed ? "#CC965300" : "transparent"
                Column{
                    width: parent.width
                    height: parent.height
                    Image{width: grid.cellWidth *4/5;height: width; source: id===""?photo:("file:"+photo); anchors.horizontalCenter: parent.horizontalCenter }
                    Text{ text: name; anchors.horizontalCenter: parent.horizontalCenter }
                }
                MouseArea{ id:mouse; anchors.fill: parent; onClicked: LayerManager.switchPop(Type.Pop_AddGroupMember) }
            }
        }
    }

    Button{
        text: "确定"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        onClicked: LayerManager.switchPop(Type.Pop_None)
    }

    Component.onCompleted: GroupMembers.update()

    Keyboard{
        id:kb
        visible: false
        width: parent.width
        height: parent.height * 2 / 5
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        onKey: {
            if(name.focus)
                name.text += content
        }
        onDel: {
            if(name.focus)
                name.text = name.text.substring(0, name.text.length - 1)
        }
    }

}
