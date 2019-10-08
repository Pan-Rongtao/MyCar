import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    signal leaveChat()

    Column{
        width: parent.width
        height: parent.height
        spacing: 30
        Text {
            id:title
            text: "uidp3575"
            width: parent.width;height: 60
            font.pixelSize: 26
            horizontalAlignment: Text.AlignHCenter;verticalAlignment: Text.AlignVCenter
        }


        ListView{
            id:list
            width: parent.width; height: parent.height - title.height - tool.height - parent.spacing * 2
            anchors.leftMargin: 10;anchors.rightMargin: anchors.leftMargin
            anchors.topMargin: 180;anchors.bottomMargin: anchors.topMargin
            model: Chat
            delegate: dlg
        }
        Row{
            id:tool
            width:parent.width;height: 50
            TextField{
                id:txtMsg
                width:parent.width-btnSend.width;height: parent.height
            }
            Button{
                id:btnSend
                text:"发送"
                font.bold: true;font.pixelSize: 24
                width:80;height: parent.height
                onClicked: {
                    txtMsg.clear()
                }
            }
        }

    }

    Component{
        id:dlg
        Rectangle{
            id:bkg;radius: 5
            width: list.width;height: x.height
            Row{
                width: list.width;height: x.height
                layoutDirection: iSend ? Qt.RightToLeft : Qt.LeftToRight
                spacing: 10
                Image{
                    id:img;width: height;height: 40
                    source: "file:///" + photo
                }
                Column{
                    id:x
                    width: parent.width - img.width
                    height: sender.height + content.height
                    Text{
                        id:sender
                        width: parent.width;height: 30
                        font.pixelSize: 16;font.bold: true
                        verticalAlignment: Text.AlignVCenter
                        color: "gray"
                        text: iSend ? "" : nickname
                    }
                    Rectangle
                    {
                        id:content
                        width: Math.min(tt.contentWidth + 20, parent.width * 0.8); height: tt.font.pixelSize*(tt.lineCount - 1)+35
                        radius: 5
                        x:iSend ? bkg.width - width - img.width : 0
                        color: iSend ? "limegreen" : "lavender"
                        Text {
                            id:tt
                            anchors.margins: 5
                            anchors.fill: parent
                            font.bold: true; font.pixelSize: 18
                            //wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignTop
                            text: msg
                            onWidthChanged: if(width>parent.width*0.8) wrapMode=Text.WrapAnywhere
                        }
                    }
                }
            }
        }
    }

    Component.onCompleted: txtMsg.focus=true

}
