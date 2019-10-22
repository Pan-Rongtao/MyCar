import QtQuick 2.0
import QtQuick.Controls 2.0
import UIT.Type 1.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    signal enterChat(string who)
    property int itemWidth: root.width * 0.24
    property int itemHeight: root.height * 0.1

    Column{
        width: parent.width
        height: parent.height
        spacing: height * 0.015
        Text {
            id:title
            text: "消息"
            width: parent.width
            height: root.height * 0.1
            font.pointSize: height * 1 / 3
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle{
            width: parent.width
            height: parent.height - title.height
            ListView{
                id:list
                anchors.fill: parent
                anchors.margins: itemHeight / 2
                model: MessageList
                delegate: dlg
            }

        }

    }

    Component{
        id:dlg
        Rectangle{
            id:bkg
            radius: 5
            width: list.width
            height: itemHeight
            Column{
                width: list.width
                height: parent.height
                Row{
                    width: list.width
                    height: parent.height - line.height
                    spacing: 10
                    Image{
                        id:img;width: height;height: parent.height-5
                        source: "file:" + photo
                    }
                    Column{
                        width: parent.width - img.width - t.width
                        height: parent.height
                        Text{
                            id:sender
                            width: parent.width;height: parent.height * 0.7
                            font.pixelSize: height * 0.5;font.bold: true
                            verticalAlignment: Text.AlignVCenter
                            text: name
                        }
                        Text {
                            width: parent.width; height: parent.height - sender.height
                            font.bold: true; font.pixelSize: height * 0.8
                            color: "gray"
                            verticalAlignment: Text.AlignVCenter
                            text: msg
                        }
                    }
                    Text{
                        id:t
                        width: parent.width * 0.3; height: sender.height
                        font.bold: true; font.pixelSize: height * 0.3
                        color: "gray"
                        verticalAlignment: Text.AlignVCenter
                        text: time
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
                onClicked: {
                    MessageList.enterChat(index)
                }
            }

        }
    }

    Component.onCompleted: MessageList.update()

}
