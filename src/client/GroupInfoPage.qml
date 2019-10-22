import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2
import UIT.Type 1.0

Rectangle {
    id:root
    anchors.fill: parent

    signal finished()
    property int itemWidth: root.width * 0.12
    property int itemHeight: root.height * 0.1

    Image{
        anchors.fill: parent
        source: "images/list_bg.png"
    }

    Column{
        width: parent.width
        height: parent.height
        spacing: height * 0.05
        Grid{
            id:layout
            rows:7
            columns: 3
            width: parent.width
            height: itemHeight
            spacing: height * 0.035
            padding: 10

            Text{ text: "群组名："; width: itemWidth; height: parent.height; font.bold: true; font.pixelSize:height * 0.333; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }
            TextField{id:name; width: parent.width - itemWidth * 2; height: itemHeight; text: GroupChat.groupName; onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible=true}
            Button{ width: height;height:itemHeight ; onClicked: GroupChat.modifyGroupName(name.text); Image{width: parent.width;height: parent.height; source: "images/notes.png"} }

        }
        Rectangle{
            width: parent.width
            height: parent.height - layout.height
            color: "transparent"
            GridView{
                id:grid
                anchors.fill: parent
                anchors.margins: itemHeight
                cellWidth: itemHeight
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
                        Image{id: img; width: grid.cellWidth *4/5;height: width; source: id===""?photo:("file:"+photo); anchors.horizontalCenter: parent.horizontalCenter }
                        Text{ text: name; anchors.horizontalCenter: parent.horizontalCenter}
                    }
                    MouseArea{ id:mouse; anchors.fill: parent; onClicked: LayerManager.switchPop(Type.Pop_AddGroupMember) }
                }
            }
        }

    }

    Button{
        text: "确定"
        width: parent.width / 3
        height: itemHeight
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
