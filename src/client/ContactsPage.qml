import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1
import UIT.Type 1.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    signal enterP2PChat(string who)
    signal enterGroupChat()

    property int itemWidth: root.width * 0.24
    property int itemHeight: root.height * 0.08
    property int removeIndex: -1

    Column{
        id:cotactsLayout
        width: parent.width
        height: parent.height
        spacing: height * 0.015
        Row{
            id:head
            width: parent.width
            height: root.height * 0.1
            Item{ width: itemWidth;height: parent.height;  }
            Rectangle{
                width: parent.width - add.width - itemWidth
                height: parent.height
                ToggleButton{
                    id:tb
                    width: itemWidth
                    height: itemHeight
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    leftString: "朋友" ;rightString: "群组"; rightColor: "deeppink"
                    toggle: true
                }
            }

            Button{
                id:add
                width: itemHeight
                height:width
                Image{width: parent.width;height: parent.height; source: "images/add_p.png"}
                onClicked: menu.open()
                Menu{
                    id:menu
                    width: itemWidth
                    MenuItem {
                        id: menuItem0
                        width: menu.width
                        height: itemHeight
                        Row{
                            width: parent.width;height: parent.height
                            Image {
                                height: height; width: parent.height
                                source: "qrc:/images/add_group.png"
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            Text {
                                width: parent.width;height: parent.height
                                text: "添加群聊"
                                color: menuItem0.down ? "#AA0000" : "#148014"
                                font.pixelSize: height * 0.5
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                        onTriggered: LayerManager.switchPop(Type.Pop_CreateGroup)
                    }
                    MenuItem {
                        id: menuItem1
                        width: menu.width
                        height: itemHeight
                        Row{
                            width: parent.width;height: parent.height
                            Image {
                                height: height; width: parent.height
                                source: "qrc:/images/add_friend.png"
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            Text {
                                width: parent.width;height: parent.height
                                text: "添加朋友"
                                color: menuItem1.down ? "#AA0000" : "#148014"
                                font.pixelSize: height * 0.5
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                        onTriggered: LayerManager.switchPop(Type.Pop_AddFriend)
                    }

                }
            }

        }

        Rectangle{
            width: parent.width
            height: parent.height - head.height - tail.height - parent.spacing * 2
            ListView{
                id:listFriend
                visible: tb.toggle
                anchors.fill: parent
                anchors.margins: 20
                model: Friends
                Component.onCompleted: Friends.update()
                onVisibleChanged: if(visible) Friends.update()
                delegate: UserItemComponent
                {
                    width: parent.width
                    height: itemHeight
                    canEdit: true
                    onMenuTriggered: Friends.remove(itemIndex)
                    onClick: {
                        P2PChat.enterFromFriendList(index)
                        LayerManager.switchPage(Type.Page_P2PChat)
                    }
                }
            }
            ListView{
                id:listGroup
                visible: !listFriend.visible
                model: Groups
                anchors.fill: parent
                anchors.margins: 20
                Component.onCompleted: Groups.update()
                onVisibleChanged: if(visible) Groups.update()
                delegate: UserItemComponent
                {
                    width: parent.width
                    height: itemHeight
                    canEdit: true
                    onMenuTriggered: Groups.remove(itemIndex)
                    onClick: {
                        GroupChat.enter(index)
                        LayerManager.switchPage(Type.Page_GroupChat)
                    }
                }
            }
        }

        Text {
            id: tail
            text: "共有 " + (tb.toggle ? listFriend.count : listGroup.count) + (tb.toggle ? " 个朋友" : " 个群组")
            width: parent.width
            height: itemHeight
            font.pixelSize: height * 0.5
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

    }

}
