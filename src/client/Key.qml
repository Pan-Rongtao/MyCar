import QtQuick 2.0

Rectangle{
    id:root
    property string content: ""
    signal click(string content)

    width: parent.width
    height: parent.height
    radius: 3
    color: mouse.pressed ? "green" : "gray"
    Text {
        color: "white"
        font.pixelSize: parent.height * 1 / 3
        font.bold: true
        anchors.centerIn: parent
        text: content
    }
    MouseArea{
        id:mouse
        anchors.fill: parent
        onClicked: click(content)
    }
}
