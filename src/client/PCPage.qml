import QtQuick 2.0
import QtQuick.Controls 1.4

Column{
    signal switchToRegPage()

    width: parent.width
    height: parent.height
    Item{width: parent.width; height: 100}
    spacing: 30

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        width: 80
        height: 50
        text: qsTr("我的电脑")
        font.pixelSize: 45
    }
    Row{
        spacing: 10
        width: parent.width
        Item{id:xx; width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ id:txt; text: "在线状态："; width: 100; font.pixelSize:20; verticalAlignment: Text.AlignVCenter }
            Image{
                width: 30
                height: 30
                source: Account.pcOnline ? "images/yes.png" : "images/cancel.png"
            }
        }

    }
    Row{
        spacing: 10
        width: parent.width
        Item{ width: 30;height: txt.height}
        Button{
            width: 200
            height: 50
            text: "关机"
            onClicked: {

            }
        }

    }
}
