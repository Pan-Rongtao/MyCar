import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import UIT.Type 1.0

Item{
    id:root
    width: parent.width
    height: parent.height

    property bool horizontal : false

    Grid {
        property int itemCount: 6
        property int itemW: horizontal ? (bar.width - bar.spacing * (itemCount - 1)) / itemCount : bar.width
        property int itemH: horizontal ? bar.height : (bar.height - bar.spacing * (itemCount - 1)) / itemCount

        id:bar
        width: parent.width
        height: parent.height
        flow: horizontal ? Grid.LeftToRight : Grid.TopToBottom
        spacing: 2
        rows:flow === Grid.LeftToRight ? 1 : itemCount
        columns:flow === Grid.LeftToRight ? itemCount : 1

        ImageButton{
            width: bar.itemW
            height: bar.itemH
            btText: "我"
            btIcon: "images/me.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: LayerManager.switchPage(Account.islogin() ? Type.Page_Account : Type.Page_Login)
        }

        ImageButton{
            width: bar.itemW
            height: bar.itemH
            btText: "我的车"
            btIcon: "images/car.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: LayerManager.switchPage(Type.Page_Car)
        }

        ImageButton{
            width: bar.itemW
            height: bar.itemH
            btText: "我的电脑"
            btIcon: "images/pc.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: LayerManager.switchPage(Type.Page_PC)
        }

        ImageButton{
            width: bar.itemW
            height: bar.itemH
            btText: "我的手机"
            btIcon: "images/phone.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: LayerManager.switchPage(Type.Page_Cellphone)
        }

        ImageButton{
            width: bar.itemW
            height: bar.itemH
            btText: "消息"
            btIcon: "images/chats.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: LayerManager.switchPage(Type.Page_Message)
        }

        ImageButton{
            width: bar.itemW
            height: bar.itemH
            btText: "联系人"
            btIcon: "images/contacts.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: LayerManager.switchPage(Type.Page_Contacts)
        }
    }
}
