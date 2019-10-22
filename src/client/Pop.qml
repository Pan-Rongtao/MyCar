import QtQuick 2.0
import QtQuick.Controls 2.1

Popup {
    property string title: "提示"
    property string content: ""
    property int autohide: 1500
    property int mode: 0

    signal btnClick(int btn)

    id: root
    anchors.centerIn: parent
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

        Column{
            anchors.fill: parent
            //设置标题栏区域为拖拽区域
            Text {
                id:tt
                width: root.width
                height: root.height * 0.2
                text: title
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height * 0.5
                font.bold: true

            }

            Rectangle{
                id:line
                width: parent.width-4
                height: 2
                radius: 8
            }

            Rectangle {
                width: parent.width
                height: parent.height - tt.height - tail.height - line.height
                color: "transparent"
                Text {
                    text: content
                    anchors.centerIn: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: tt.font.pixelSize * 0.8
                    font.bold: true
                }

            }

            Row{
                id: tail
                width: root.width
                height: root.height * 0.3
                Rectangle{
                    width: parent.width / 2
                    height: parent.height
                    color: "transparent"
                    Button {
                        width: parent.width * 0.7
                        height: parent.height * 0.7
                        text: "取消"
                        anchors.centerIn: parent
                        visible: mode == 1
                        font.bold: true
                        onClicked: {
                            root.close()
                            btnClick(0)
                        }
                    }
                }
                Rectangle{
                    width: parent.width / 2
                    height: parent.height
                    color: "transparent"
                    Button {
                        text: "确定"
                        width: parent.width * 0.7
                        height: parent.height * 0.7
                        anchors.centerIn: parent
                        visible: mode == 1
                        font.bold: true
                        onClicked: {
                            root.close()
                            btnClick(1)
                        }
                    }
                }

            }
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
