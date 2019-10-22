import QtQuick 2.0
import QtQuick.Controls 2.0
import UIT.Type 1.0

Rectangle {
    id:root
    anchors.fill: parent
    radius: 5

    property var checkItems: []
    property int itemWidth: root.width * 0.24
    property int itemHeight: root.height * 0.08

    Image{ anchors.fill: parent; source: "images/list_bg.png" }

    Text {
        width: parent.width
        height: itemHeight
        font.bold: true
        font.pixelSize: height * 0.5;
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "blue"
        text: LayerManager.currentPop === Type.Pop_CreateGroup ? "创建群聊" : "添加群成员"
    }
    ListView{
        id:list
        anchors.fill: parent
        anchors.leftMargin: 30;anchors.rightMargin: anchors.leftMargin
        anchors.topMargin: 100;anchors.bottomMargin: anchors.topMargin
        model: Friends
        delegate: UserItemComponent{
            width: parent.width
            height: itemHeight
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
            if(LayerManager.currentPop === Type.Pop_CreateGroup)
                Groups.create(checkItems)
            else
                GroupMembers.addMember(checkItems)
            LayerManager.switchPop(Type.Pop_None)
        }
    }

    Component.onCompleted: Friends.update()
}
