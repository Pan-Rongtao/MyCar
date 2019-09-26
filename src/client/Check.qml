import QtQuick 2.0

Rectangle {
    id:root
    property int state: -1
    property string emptyTip: ""
    property string refuseTip: ""


    Image{
        id:img
        source: "images/yes.png"
        width: 30
        height: 30
        visible: root.state===1
    }

    Text{
        id:txt
        visible: text!==""
        width: parent.width
        height: parent.height
        verticalAlignment: Text.AlignHCenter
        font.bold: true
        color: "red"
    }

    onStateChanged: txt.text = state == -1 ? emptyTip : (state == 0 ? refuseTip : "")
}
