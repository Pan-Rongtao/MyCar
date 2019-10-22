import QtQuick 2.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"
    property int itemWidth: root.width * 0.12
    property int itemHeight: root.height * 0.08

    Column{
        width: parent.width
        height: parent.height
        spacing: height * 0.035
        Text {
            text: "我的手机"
            width: parent.width
            height: root.height * 0.1
            font.pointSize: height * 1 / 3
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Row{
            spacing: 10
            width: parent.width; height: itemHeight
            Item{width: itemWidth;height: itemHeight}
            Row{
                width: parent.width
                height: parent.height
                Text{ text: "在线状态："; width: itemWidth; height: parent.height; font.pixelSize: height * 0.33; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }
                Image{ width: height;height: itemHeight; source: Account.handeldOnline ? "images/yes.png" : "images/cancel.png" }
            }

        }
    }
}
