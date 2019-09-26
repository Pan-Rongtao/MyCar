import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Item{
    id:root
    width: parent.width
    height: parent.height

    signal naviTo(int page);
    property bool horizontal : false
    property int itemCount: 6

    Grid {
        id:bar
        width: parent.width
        height: parent.height
        flow: horizontal ? Grid.LeftToRight : Grid.TopToBottom
        spacing: 2
        rows:flow === Grid.LeftToRight ? 1 : itemCount
        columns:flow === Grid.LeftToRight ? itemCount : 1

        ImageButton{
            width: horizontal ? bar.width / itemCount : bar.width
            height: horizontal ? bar.height : bar.height / itemCount
            btText: "我"
            btIcon: "images/me.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: naviTo(0)
        }

        ImageButton{
            width: horizontal ? bar.width / itemCount : bar.width
            height: horizontal ? bar.height : bar.height / itemCount
            btText: "我的车"
            btIcon: "images/car.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: naviTo(1)
        }

        ImageButton{
            width: horizontal ? bar.width / itemCount : bar.width
            height: horizontal ? bar.height : bar.height / itemCount
            btText: "我的电脑"
            btIcon: "images/pc.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: naviTo(2)
        }

        ImageButton{
            width: horizontal ? bar.width / itemCount : bar.width
            height: horizontal ? bar.height : bar.height / itemCount
            btText: "我的手机"
            btIcon: "images/phone.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: naviTo(3)
        }

        ImageButton{
            width: horizontal ? bar.width / itemCount : bar.width
            height: horizontal ? bar.height : bar.height / itemCount
            btText: "消息"
            btIcon: "images/chats.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: naviTo(4)
        }

        ImageButton{
            width: horizontal ? bar.width / itemCount : bar.width
            height: horizontal ? bar.height : bar.height / itemCount
            btText: "联系人"
            btIcon: "images/contacts.png"
            pressedColor: "#33003300"
            releaseColor: "#33965300"
            pressedTextColor:"green"
            onClicked: naviTo(5)
        }
    }
}
