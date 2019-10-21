import QtQuick 2.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    Column{
        width: parent.width
        height: parent.height
        spacing: 30
        Text {
            text: qsTr("我的手机")
            width: parent.width;height: 80
            font.pixelSize: 32
            horizontalAlignment: Text.AlignHCenter;verticalAlignment: Text.AlignVCenter
        }

        Row{
            spacing: 10
            width: parent.width; height: 30
            Item{width: 30;height: parent.height}
            Row{
                width: 80
                Text{ text: "在线状态："; width: 100; height: parent.height; font.pixelSize:20; verticalAlignment: Text.AlignVCenter }
                Image{ width: 30;height: 30; source: Account.handeldOnline ? "images/yes.png" : "images/cancel.png" }
            }

        }
    }
}
