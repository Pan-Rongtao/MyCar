import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2

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
            TextField{id:name; width: parent.width - item0Width - item2Width; height: item0Height; text: GroupChat.groupName; }
            Button{ width: 30;height:item0Height ; onClicked: GroupChat.modifyGroupName(name.text); Image{width: parent.width;height: parent.height; source: "images/notes.png"} }


        }
        ListView{
            id:list
            anchors.fill: parent
            anchors.leftMargin: 30;anchors.rightMargin: anchors.leftMargin
            anchors.topMargin: 100;anchors.bottomMargin: anchors.topMargin
            model: GroupMembers
            delegate: dlg
        }
    }

    Component{
        id:dlg
        Rectangle{
            id:bkg;radius: 5
            width: list.width;height: 40
            color: "transparent"
            Column{
                width: list.width;height: parent.height
                Row{
                    width: list.width;height: parent.height - line.height
                    spacing: 30
                    Image{
                        id:img;width: height;height: parent.height
                        source: "file:" + photo
                    }
                    Text{
                        width: parent.width - img.width - 60; height: img.height
                        font.pixelSize: 20; font.bold: true
                        verticalAlignment: Text.AlignVCenter
                        text:name
                    }
                }
                Image{
                    id:line
                    width: parent.width;height: 1
                    source: "/images/line.png"
                }
            }

            MouseArea{
                anchors.fill: bkg
                onPressed: bkg.color = "#33003300"
                onReleased:  bkg.color = "transparent"
                onCanceled:  bkg.color = "transparent"
            }
        }
    }

    Component.onCompleted: GroupMembers.update()

}
