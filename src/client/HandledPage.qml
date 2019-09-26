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
            width: parent.width;height: 100
            font.pixelSize: 45
            horizontalAlignment: Text.AlignHCenter;verticalAlignment: Text.AlignVCenter
        }
    }
}
