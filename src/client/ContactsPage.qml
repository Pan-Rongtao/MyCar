import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    signal enterChat(string who)

    property int item0Width: 20
    property int removeIndex: -1

    Column{
        id:cotactsLayout
        width: parent.width
        height: parent.height
        spacing: 30

        Row{
            width: parent.width;height: 80
            Item{ width: item0Width;height: parent.height;  }
            Text {
                id: head
                text: qsTr("联系人")
                width: parent.width - add.width - item0Width;height: parent.height
                font.pixelSize: 32
                horizontalAlignment: Text.AlignHCenter;verticalAlignment: Text.AlignVCenter
            }


            Button{ id:add; width: 50;height:width;
                Image{width: parent.width;height: parent.height; source: "images/add_p.png"}
                onClicked: userlist.visible=true;
            }

        }

        Row{
            width: parent.width
            height: parent.height - head.height - tail.height - cotactsLayout.spacing * 2
            Item{ width: item0Width;height: parent.height;  }
            ListView{
                id:list
                width: parent.width - item0Width * 2
                height: parent.height
                model: Contacts
                delegate: dlg
            }
            Item{ width: item0Width;height: parent.height; }
        }

        Text {
            id: tail
            text: "共有 " + list.count + " 位联系人"
            width: parent.width;height: 30
            font.pixelSize: 18;font.bold: true
            horizontalAlignment: Text.AlignHCenter;verticalAlignment: Text.AlignVCenter
        }

        Component{
            id:dlg
            Rectangle{
                id:bkg;radius: 5
                width: list.width;height: 45
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
                            id:nick
                            width: parent.width - img.width; height: img.height
                            font.pixelSize: 20; font.bold: true
                            verticalAlignment: Text.AlignVCenter
                            text:nickname
                        }
                    }
                    Image{
                        id:line
                        width: parent.width;height: 1
                        source: "/images/line.png"
                    }
                }

                Menu{
                    id: menu
                    width: parent.width
                    MenuItem {
                        id: menuItem1
                        height: bkg.height
                        contentItem: Text {
                            id: text1
                            text: "删除"
                            font.bold: true;font.pixelSize: 18
                            anchors.fill: parent
                            opacity: enabled ? 1.0 : 0.3
                            color: menuItem1.down ? "#AA0000" : "#148014"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                        onTriggered: Contacts.remove(removeIndex)
                    }
                }
                MouseArea{
                    anchors.fill: bkg
                    onPressed: bkg.color = "#33003300"
                    onReleased:  bkg.color = "transparent"
                    onCanceled:  bkg.color = "transparent"
                    onPressAndHold: {removeIndex = index; menu.open()}
                    onClicked: enterChat(nick.text)
                }

            }
        }
    }


    UsersPage{
        id:userlist
        anchors.fill: parent
        anchors.margins: 25
        visible: false
        onFinished: visible = false
        onVisibleChanged:
        {
            if(visible)
                Users.query()
            else
                Contacts.update()
        }

    }

    Component.onCompleted:    Contacts.update()

}
