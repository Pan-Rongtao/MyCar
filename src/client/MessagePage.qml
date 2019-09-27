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
            text: qsTr("消息")
            width: parent.width;height: 80
            font.pixelSize: 32
            horizontalAlignment: Text.AlignHCenter;verticalAlignment: Text.AlignVCenter
        }


    }
}
