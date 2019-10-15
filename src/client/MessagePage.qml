import QtQuick 2.0
import QtQuick.Controls 2.0
import UIT.Type 1.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    signal enterChat(string who)

    Column{
        width: parent.width
        height: parent.height
        spacing: 30
        Text {
            text: qsTr("消息")
            width: parent.width;height: 80
            font.pixelSize: 32
            horizontalAlignment: Text.AlignHCenter;verticalAlignment: Text.AlignVCenter
        }


        ListView{
            id:list
            anchors.fill: parent
            anchors.leftMargin: 20;anchors.rightMargin: anchors.leftMargin
            anchors.topMargin: 120;anchors.bottomMargin: anchors.topMargin
            model: MessageList
            delegate: dlg
        }

    }

    Component{
        id:dlg
        Rectangle{
            id:bkg
            radius: 5
            width: list.width
            height: 50
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
                            width: parent.width;height: 30
                            font.pixelSize: 20;font.bold: true
                            verticalAlignment: Text.AlignVCenter
                            text: name
                        }
                        Text {
                            width: parent.width; height: parent.height - sender.height
                            font.bold: true; font.pixelSize: 14
                            color: "gray"
                            verticalAlignment: Text.AlignVCenter
                            text: msg
                        }
                    }
                    Text{
                        id:t
                        width: 120; height: sender.height
                        font.bold: true; font.pixelSize: 12
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
