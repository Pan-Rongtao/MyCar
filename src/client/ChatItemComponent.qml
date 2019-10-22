import QtQuick 2.0

Rectangle{
    id:root
    radius: 5
    width: parent.width
    height: c.height

    Row{
        width: parent.width
        height: c.height
        layoutDirection: iSend ? Qt.RightToLeft : Qt.LeftToRight
        spacing: 10
        Image{
            id:img
            width: height
            height: parent.width * 0.1
            source: "file:" + photo
        }
        Column{
            id:c
            width: parent.width - img.width
            height: sender.height + content.height
            Text{
                id:sender
                width: parent.width
                height: img.height * 0.7
                font.pixelSize: height * 0.6
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                color: "gray"
                text: iSend ? "" : name
            }
            Rectangle
            {
                id:content
                width: Math.min(tt.contentWidth + 20, root.width * 0.8)
                height: tt.font.pixelSize*(tt.lineCount - 1) + tt.font.pixelSize * 1.5
                radius: 5
                x:iSend ? root.width - width - img.width : 0
                color: iSend ? "limegreen" : "lavender"
                Text {
                    id:tt
                    anchors.margins: 5
                    anchors.fill: parent
                    font.bold: true
                    font.pixelSize: sender.font.pixelSize
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignTop
                    onWidthChanged: if(width>parent.width*0.8) wrapMode=Text.WrapAnywhere
                    text: msg
                }
            }
        }
    }
}
