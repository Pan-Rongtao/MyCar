import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import UIT.Type 1.0

Window {
    id:window
    visible: true
    width: Proxy.terminalType === Type.Terminal_PC ? 400 : (Proxy.terminalType === Type.Terminal_Vehicle ? 1920 : 480)
    height: Proxy.terminalType === Type.Terminal_PC ? 720 : (Proxy.terminalType === Type.Terminal_Vehicle ? 720 : 480)
    minimumWidth: 400
    minimumHeight: 720
    title: Proxy.connected ? "connect success" : " connect fail"

    Rectangle{
        anchors.fill: parent
        Item{
            width: bar.horizontal ? window.width : window.width - bar.width
            height: bar.horizontal ? window.height - bar.height : window.height
            anchors.left: bar.horizontal ? parent.left : bar.right
            Loader{
                id:pageContainer
                width: parent.width
                height: parent.height
            }
            Loader{
                id:popContainer
                width: parent.width
                height: parent.height
            }

            Connections{
                target: LayerManager
                onCurrentPageChanged :
                {
                    switch(LayerManager.currentPage)
                    {
                    case Type.Page_Regist:      pageContainer.source = "RegistPage.qml";    break;
                    case Type.Page_Login:       pageContainer.source = "LoginPage.qml";     break;
                    case Type.Page_Account:     pageContainer.source = "MyAccountPage.qml"; break;
                    case Type.Page_Car:         pageContainer.source = "CarPage.qml";       break;
                    case Type.Page_PC:          pageContainer.source = "PCPage.qml";        break;
                    case Type.Page_Cellphone:   pageContainer.source = "CellphonePage.qml"; break;
                    case Type.Page_Message:     pageContainer.source = "MessagePage.qml";   break;
                    case Type.Page_Contacts:    pageContainer.source = "ContactsPage.qml";  break;
                    case Type.Page_P2PChat:     pageContainer.source = "P2PChatPage.qml";   break;
                    case Type.Page_GroupChat:   pageContainer.source = "GroupChatPage.qml"; break;
                    default: break
                    }
                }
                onCurrentPopChanged:
                {
                    switch(LayerManager.currentPop)
                    {
                    case Type.Pop_None:         popContainer.source = "";  break;
                    case Type.Pop_AddFriend:    popContainer.source = "AddFriendPage.qml";  break;
                    case Type.Pop_AddGroupMember:popContainer.source = "CreateGroupPage.qml";break;
                    case Type.Pop_CreateGroup:  popContainer.source = "CreateGroupPage.qml";break;
                    case Type.Pop_GroupInfo:    popContainer.source = "GroupInfoPage.qml";  break;
                    default: break;
                    }

                }
            }

            Image{
                width:parent.width
                height: parent.height
                source: "images/bg.jpg"
                opacity: 0.3
            }

            Pop{
                width: parent.width
                height: parent.height / 2
                content: "请先登录"
                autohide: 1500
                visible: LayerManager.notLoginWarn
            }
        }

        PushBox{
            id:pb
            width: parent.width
            height: 80
            active: MessageList.newMessage
        }

        NaviBar{
            id:bar
            width: horizontal ? window.width : window.width * 0.2
            height: horizontal ? window.height * 0.2 : window.height
            horizontal: window.width < window.height
            anchors.bottom: parent.bottom
        }

    }
    Component.onCompleted: {LayerManager.switchPage(Type.Page_Login); if(Proxy.terminalType === Type.Terminal_Vehicle) window.flags = Qt.FramelessWindowHint }
    Component.onDestruction: Account.logout(Account.userID, Account.password)

}
