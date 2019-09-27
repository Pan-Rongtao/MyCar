import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    Column{
        width: parent.width
        height: parent.height
        spacing: 30
        Text {
            text: qsTr("我的电脑")
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
                Image{ width: 30;height: 30; source: Account.pcOnline ? "images/yes.png" : "images/cancel.png" }
            }

        }

        Row{
            spacing: 10
            width: parent.width; height: 50
            Item{ width: (parent.width - btn.width) / 2; height: parent.height}
            Button{ id:btn; width: 200; height: 50; text: "关机"; onClicked: pop.open(); }
        }
    }

    Pop{id:pop; autohide : 100000; mode:1; content: "该操作将关闭您的远程计算机，确定要这么做么？"
        onBtnClick:  if(btn === 1);
    }
}
