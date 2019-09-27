import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    anchors.fill: parent

    signal finished()
    //color: "red"
    radius: 5

    Image{
        anchors.fill: parent
        source: "file:///D:/Qt_Project/svcar/img/CourseMgrPage/bg_790x431.png"
    }

    Text {
        width: parent.width
        height: 50
        font.bold: true;font.pixelSize: 22;
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "blue"
        text: "添加朋友"
    }
    ListView{
        id:list
        anchors.fill: parent
        anchors.leftMargin: 30;anchors.rightMargin: anchors.leftMargin
        anchors.topMargin: 100;anchors.bottomMargin: anchors.topMargin
        model: Users
        delegate: dlg
    }


    Button{id:cancel;text: "取消"; anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom; anchors.bottomMargin: 20; anchors.horizontalCenterOffset: -80
        onClicked: finished()
    }
    Button{id:ok;text: "确定"; anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom; anchors.bottomMargin: 20; anchors.horizontalCenterOffset: 80
        onClicked: finished()
    }

    Component{
        id:dlg
            Rectangle{
                id:bkg;radius: 5
                width: list.width;height: 40
                color: "transparent"
                Column{
                    width: list.width;height: parent.height
                    Row{
                        width: list.width;height: parent.height - line.height
                        spacing: 30
                        Text{
                            id:img;width: height;height: parent.height
                            font.pixelSize: 20; font.bold: true
                            verticalAlignment: Text.AlignVCenter
                            text:userID
                        }
                        Text{
                            width: parent.width - img.width - check.width - 60; height: img.height
                            font.pixelSize: 20; font.bold: true
                            verticalAlignment: Text.AlignVCenter
                            text:nickname
                        }
                        CheckBox{
                            id:check
                            width: 30;height: 30
                        }
                    }
                    Image{
                        id:line
                        width: parent.width;height: 1
                        source: "/images/line.png"
                    }
                }

                MouseArea{
                    anchors.fill: bkg
                    onPressed: bkg.color = "#33003300"
                    onReleased:  bkg.color = "transparent"
                    onCanceled:  bkg.color = "transparent"
                    onClicked: check.checked = !check.checked
                }
            }
        }

}
