import QtQuick 2.0
import QtQuick.Controls 1.4

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
            text: "我的电脑"
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
                Image{ width: height;height: itemHeight; source: Account.pcOnline ? "images/yes.png" : "images/cancel.png" }
            }

        }

        Rectangle{
            width: parent.width
            height: itemHeight
            Button{ id:btn; width: parent.width * 0.5; height: parent.height; anchors.centerIn: parent; text: "关机"; onClicked: pop.open(); }
        }

    }

    Pop{id:pop; autohide : 100000; mode:1; content: "该操作将关闭您的远程计算机，确定要这么做么？"
        onBtnClick:{
            if(btn === 1)
                Account.shutdownPC()
            }
    }
}
