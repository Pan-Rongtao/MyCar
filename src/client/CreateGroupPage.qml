import QtQuick 2.0
import QtQuick.Controls 2.0
import UIT.Type 1.0

Rectangle {
    anchors.fill: parent
    radius: 5

    property var checkItems: []

    Image{ anchors.fill: parent; source: "images/list_bg.png" }

    Text {
        width: parent.width
        height: 50
        font.bold: true
        font.pixelSize: 22
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "blue"
        text: "创建群聊"
    }
    ListView{
        id:list
        anchors.fill: parent
        anchors.leftMargin: 30;anchors.rightMargin: anchors.leftMargin
        anchors.topMargin: 100;anchors.bottomMargin: anchors.topMargin
        model: Friends
        delegate: UserItemComponent{
            width: parent.width
            height: 40
            canCheck: true
            onCheck:
            {
                if(check)
                    checkItems.push(index)
                else
                    checkItems.splice(checkItems.indexOf(index), 1)
            }
        }
    }

    Button{
        text: "取消"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.horizontalCenterOffset: -80
        onClicked: LayerManager.switchPop(Type.Pop_None)
    }
    Button{
        text: "确定"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.horizontalCenterOffset: 80
        onClicked:
        {
            checkItems.sort()
            Groups.create(checkItems)
            LayerManager.switchPop(Type.Pop_None)
        }
    }

    Component.onCompleted: Friends.update()
}
