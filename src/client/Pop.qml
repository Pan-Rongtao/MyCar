import QtQuick 2.0
import QtQuick.Controls 2.1

Popup {
    property string title: "提示"
    property string content: ""
    property int autohide: 1500
    property int mode: 0

    signal btnClick(int btn)

    id: root
    x: parent.width/2 - root.width/2
    y: parent.height/2 - root.height/2
    width: 530
    height: 300
    modal: true
    focus: true
    //设置窗口关闭方式为按“Esc”键关闭
    //closePolicy: Popup.OnEscape
    //设置窗口的背景控件，不设置的话Popup的边框会显示出来
    background: rect

    Rectangle {
        id: rect
        anchors.fill: parent
        color: "orange"
        border.width: 2
        opacity: 1
        radius: 8

        Rectangle{
            width: parent.width-4
            height: 2
            anchors.top: parent.top
            anchors.topMargin: 40
            anchors.left: parent.left
            anchors.leftMargin: 2
            radius: 8
        }

        //设置标题栏区域为拖拽区域
        Text {
            width: parent.width
            height: 40
            anchors.top: parent.top
            text: title
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 22
            font.bold: true

            MouseArea {
                property point clickPoint: "0,0"

                anchors.fill: parent
                acceptedButtons: Qt.LeftButton
                onPressed: {
                    clickPoint  = Qt.point(mouse.x, mouse.y)
                }
                onPositionChanged: {
                    var offset = Qt.point(mouse.x - clickPoint.x, mouse.y - clickPoint.y)
                    setDlgPoint(offset.x, offset.y)
                }
            }
        }

        Text {
            x: 189
            y: 128
            width: 171
            height: 15
            text: content
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 14
            font.bold: true
        }
/*
        Label {
            x: 189
            y: 128
            width: 171
            height: 15
            text: content
        }
*/
        Button {
            x: 103
            y: 204
            text: "取消"
            visible: mode == 1
            font.bold: true
            onClicked: {
                root.close()
            }
        }

        Button {
            x: 341
            y: 204
            text: qsTr("确定")
            visible: mode == 1
            font.bold: true
            onClicked: {
                root.close()
            }
        }
    }

    function setDlgPoint(dlgX ,dlgY)
    {
        //设置窗口拖拽不能超过父窗口
        if(root.x + dlgX < 0)
        {
            root.x = 0
        }
        else if(root.x + dlgX > root.parent.width - root.width)
        {
            root.x = root.parent.width - root.width
        }
        else
        {
            root.x = root.x + dlgX
        }
        if(root.y + dlgY < 0)
        {
            root.y = 0
        }
        else if(root.y + dlgY > root.parent.height - root.height)
        {
            root.y = root.parent.height - root.height
        }
        else
        {
            root.y = root.y + dlgY
        }
    }

    onOpened: timer.start()

    Timer{
        id:timer
        repeat: false
        interval: autohide
        onTriggered: {
            root.close()
        }
    }

}
