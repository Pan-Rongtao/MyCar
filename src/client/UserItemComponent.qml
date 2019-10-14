import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle{
    id:root
    radius: 5
    width: parent.width
    height: parent.height
    color: "transparent"

    signal check(bool check);
    signal click(int index)
    signal menuTriggered(int itemIndex, int menuIndex);

    property bool canCheck: false
    property bool canEdit: false
    property int longPressIndex: -1

    Column{
        width: parent.width
        height: parent.height
        Row{
            id:main
            width: parent.width
            height: parent.height - line.height
            spacing: 30
            Image{
                id:img
                width: height
                height: parent.height
                source: "file:" + photo
            }
            Text{
                width: parent.width - img.width - cb.width - parent.spacing * 2
                height: img.height
                font.pixelSize: 20
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                text:name
            }
            CheckBox{
                id:cb
                width: 30
                height: width
                anchors.verticalCenter: parent.verticalCenter
                visible: canCheck
            }
        }
        Image{
            id:line
            width: parent.width
            height: 1
            source: "/images/line.png"
        }
    }
    Menu{
        id: menu
        width: root.width
        height: root.height
        MenuItem {
            id: item
            Text {
                text: "删除"
                anchors.fill: parent
                font.bold: true
                font.pixelSize: 18
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: item.down ? "#AA0000" : "#148014"
            }
            onTriggered: menuTriggered(longPressIndex, 0)
        }
    }

    MouseArea{
        anchors.fill: parent
        onPressed:  root.color = "#33003300"
        onReleased: root.color = "transparent"
        onCanceled: root.color = "transparent"
        onPressAndHold: {
            longPressIndex = index
            if(canEdit)
                menu.open()
        }
        onClicked: {
            cb.checked = !cb.checked
            check(cb.checked)
            click(index)
        }
    }
}
