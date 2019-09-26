import QtQuick 2.0

Column{
    anchors.fill: parent
    signal switchToRegPage()

    Item{width: parent.width; height: 100}
    spacing: 30

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        width: 80
        height: 50
        text: qsTr("消息")
        font.pixelSize: 45
    }
    Row{
        spacing: 10
        width: parent.width
        Item{id:xx; width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ id:txt; text: "账号："; width: 100; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
        }

    }
}
