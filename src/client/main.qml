import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Window {
    id:window
    visible: true
    width: 400
    height: 720
    minimumWidth: 400
    minimumHeight: 720
    title: "svcar"

    Rectangle{
        anchors.fill: parent
        NaviBar{
            id:bar
            width: horizontal ? window.width : window.width * 0.2
            height: horizontal ? window.height * 0.2 : window.height
            horizontal: window.width < window.height
            anchors.bottom: parent.bottom
            onNaviTo: {
                if(!Account.islogin())            {pop.open(); return;}
                if(page === "me")               pageContainer.source = Account.islogin ? "MePage.qml" : "LoginPage.qml"
                else if(page === "car")         pageContainer.source = "CarPage.qml"
                else if(page === "pc")          pageContainer.source = "PCPage.qml"
                else if(page === "cellphone")   pageContainer.source = "HandledPage.qml"
                else if(page === "message")     pageContainer.source = "MessagePage.qml"
                else if(page === "contacts")    pageContainer.source = "ContactsPage.qml"
            }
        }

        Item{
            width: bar.horizontal ? window.width : window.width - bar.width
            height: bar.horizontal ? window.height - bar.height : window.height
            anchors.left: bar.horizontal ? parent.left : bar.right

            Loader{
                id:pageContainer
                width: parent.width
                height: parent.height
            //    source: "LoginPage.qml"
            }
            Connections{
                target: pageContainer.item
                onNaviToLogin: pageContainer.source = "LoginPage.qml"
                onNaviToRegist: pageContainer.source = "RegistPage.qml"
                onLoginResult: if(success) pageContainer.source = "MePage.qml"
                onLogout: pageContainer.source = "LoginPage.qml"
                onEnterP2PChat: {pageContainer.source = "P2PChatPage.qml"; P2PChat.who = who}
                onEnterGroupChat : {pageContainer.source = "GroupChatPage.qml"}
            }

            Image{
                width:parent.width
                height: parent.height
                source: "images/bg.jpg"
                opacity: 0.3
                //visible: false
            }

            Pop{
                id:pop
                content: "请先登录"
                autohide: 1500
            }

        }
    }
    Component.onCompleted: pageContainer.source = "LoginPage.qml"
    Component.onDestruction: Account.logout(Account.userID, Account.password)

}
