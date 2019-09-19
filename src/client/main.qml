import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Window {
    id:w
    visible: true
    width: 1080
    height: 720
    title: "svcar:  [" + (Account.connected ? "connected" : "disconnected") + "]"

    NaviBar{
        id:bar
        width: parent.width * (1.5/5)
        visible: true
        onSwitchPage: pages.switchPage(page)
    }

    Item
    {
        id:pages
        anchors.left: bar.right
        width: w.width - bar.width
        height: w.height
        Image{
            width:parent.width
            height: parent.height
            source: "img/picSelect/Lnk/1.jpg"
            opacity: 0.3
        }

        CarPage{ id:carPg; visible: false }
        PCPage{ id:pcpg; visible: false }
        HandledPage{ id:handledPg; visible:false }
        MessagePage{ id:msgPg; visible: false }
        ContactsPage{ id:contactsPg; visible: false }
        /////
        LoginPage{ id:loginPg; visible: false; onSwitchPage: pages.switchPage(page) }
        RegistPage{ id:regPg; visible: false; onSwitchPage: pages.switchPage(page) }
        MyAccountPage{ id:myaccountPg; visible: false; onSwitchPage: pages.switchPage(page) }

        function switchPage(page)
        {
            carPg.visible = false
            pcpg.visible = false
            handledPg.visible = false
            msgPg.visible = false
            contactsPg.visible = false
            regPg.visible = false
            loginPg.visible = false
            myaccountPg.visible = false

            if(page === 0)          carPg.visible = true
            else if(page === 1)     pcpg.visible = true
            else if(page === 2)     handledPg.visible = true
            else if(page === 3)     msgPg.visible = true
            else if(page === 4)     contactsPg.visible = true
            else if(page === 5)     regPg.visible = true
            else if(page === 6)     loginPg.visible = true
            else if(page === 7)     myaccountPg.visible = true
        }
    }

    Component.onCompleted: {
        pages.switchPage(6)
    }

    Component.onDestruction: Account.logout(Account.userID, Account.password)

}
