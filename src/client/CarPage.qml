import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    property int item0Width: 100
    property int item2Width: 80
    property int item0Height: 30

    property int itemWidth: 80
    property int itemHeight: 26

    Column{
        width: parent.width
        height: parent.height
        spacing: 10
        Text {
            id:head
            text: qsTr("我的车")
            width: parent.width
            height: 80
            font.pixelSize: 32
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            width: 80
            height: 50
            text: "30" + "km/h"
            font.pixelSize: 30
        }

        GroupBox{
            id:carInfoGroup
            title: "车辆信息"
            width: parent.width
            height: 120
            Column{
                x:20
                width: parent.width
                height: parent.height
                spacing: 6
                Text{ text: "剩余油量：" + Car.availableFuel + "%";  horizontalAlignment: Text.AlignLeft; }
                Text{ text: "平均油耗：" + Car.averageFuel + "L/100km";  horizontalAlignment: Text.AlignLeft }
                Text{ text: "总行驶里程：" + Car.totalKm + "km"; horizontalAlignment: Text.AlignLeft }
                Text{ text: "小计里程A：" + Car.subKmA + "km"; horizontalAlignment: Text.AlignLeft }
                Text{ text: "小计里程B：" + Car.subKmB + "km"; horizontalAlignment: Text.AlignLeft }
                }
            }

        GroupBox{
            title: "车辆控制"
            width: carInfoGroup.width
            height: 180
            GridLayout{
                columns:2
                columnSpacing: 50
                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "左前车门："; verticalAlignment: Text.AlignVCenter;  }
                    ToggleButton{
                        width: itemWidth; height: itemHeight; leftString: qsTr("打开"); rightString: qsTr("关闭")
                        toggle:Car.leftFrontDoor
                        onToggled: { Car.switchLeftFrontDoor(on) }
                    }
                }

                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "右前车门："; verticalAlignment: Text.AlignVCenter;  }
                    ToggleButton{
                        width: itemWidth; height: itemHeight
                        toggle:Car.rightFrontDoor
                        leftString: qsTr("打开") ;rightString: qsTr("关闭")
                        onToggled: Car.switchRightFrontDoor(on)
                    }
                }
                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "左后车门："; verticalAlignment: Text.AlignVCenter;  }
                    ToggleButton{  width: itemWidth; height: itemHeight; leftString: qsTr("打开"); rightString: qsTr("关闭")
                        toggle:Car.leftRearDoor
                        onToggled: Car.switchLeftRearDoor(on)
                    }
                }
                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "右后车门："; verticalAlignment: Text.AlignVCenter;  }
                    ToggleButton{
                        width: itemWidth;height: itemHeight; leftString: qsTr("打开");rightString: qsTr("关闭")
                        toggle:Car.rightRearDoor
                        onToggled: Car.switchRightRearDoor(on)
                    }
                }
                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "左前车窗："; verticalAlignment: Text.AlignVCenter;  }
                    ToggleButton{
                        width: itemWidth; height: itemHeight; leftString: qsTr("打开"); rightString: qsTr("关闭")
                        toggle:Car.leftFrontWindow
                        onToggled: Car.switchLeftFrontWindow(on)
                    }
                }
                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "右前车窗："; verticalAlignment: Text.AlignVCenter;  }
                    ToggleButton{
                        width: itemWidth; height: itemHeight; leftString: qsTr("打开"); rightString: qsTr("关闭")
                        toggle:Car.rightFrontWindow
                        onToggled: Car.switchRightFrontWindow(on)
                    }
                }
                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "左后车窗："; verticalAlignment: Text.AlignVCenter;  }
                    ToggleButton{
                        width: itemWidth; height: itemHeight; leftString: qsTr("打开"); rightString: qsTr("关闭")
                        toggle:Car.leftRearWindow
                        onToggled: Car.switchLeftRearWindow(on)
                    }
                }
                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "右后车窗："; verticalAlignment: Text.AlignVCenter;  }
                    ToggleButton{
                        width: 80; height: itemHeight; leftString: qsTr("打开"); rightString: qsTr("关闭")
                        toggle:Car.rightRearWindow
                        onToggled: Car.switchRightRearWindow(on)
                    }
                }

                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "空调开关："; verticalAlignment: Text.AlignVCenter;  }
                    ToggleButton{
                        width: itemWidth; height: itemHeight; leftString: qsTr("打开"); rightString: qsTr("关闭")
                        toggle:Car.AC
                        onToggled: Car.switchAC(on)
                    }
                }
                Row{
                    spacing: 10
                    Text { height: itemHeight; text: "空调温度："; verticalAlignment: Text.AlignVCenter;  }
                    Slider{ id:slider; width:itemWidth; height: itemHeight; minimumValue: 18; maximumValue: 30; stepSize: 1;updateValueWhileDragging: false
                        property bool firstTime: true
                        value: Car.ACTemp
                        onValueChanged:{
                            if(!firstTime)
                                Car.switchACTemp(value)
                            firstTime = false
                        }
                    }
                    Text {height: itemHeight; text: slider.value;verticalAlignment: Text.AlignVCenter}
                }
            }

        }

        Grid{
            width: parent.width
            height: 80
            Item{width: (parent.width - cProBtn.width) / 2;height: parent.height}
            Rectangle{
                property int btnHeight: parent.height
                property int btnWidth: parent.width * 0.4

                id: cProBtn
                height: btnHeight
                width: btnWidth
                border.color: "#148014"
                border.width: 2
                radius: 0
                Text{
                    id: cText
                    anchors.centerIn: parent
                    font.family: "microsoft yahei"
                    font.pixelSize: 14
                    text: Car.driving ? "熄火" : "启动"
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if (rAniStart.running || rAniStop.running) return
                        cText.visible = false;
                        rAniStart.start();
                        widthAniStart.start();
                    }
                }
                PropertyAnimation{
                    id: rAniStart
                    target: cProBtn
                    property: "radius"
                    duration: 300
                    from: 0
                    to: cProBtn.btnHeight/2
                    onStopped: {
                        cProgress.onStart();
                        cProgress.visible = true;
                    }
                }
                PropertyAnimation{
                    id: widthAniStart
                    target: cProBtn
                    property: "width"
                    duration: 300
                    from: cProBtn.btnWidth
                    to: cProBtn.btnHeight
                }
                CircularProgress{
                    id: cProgress
                    anchors.centerIn: parent
                    visible: false
                    arcWidth: 2
                    radius: cProBtn.btnHeight/2
                    interval: 2
                    arcColor: "#148014"
                    onSStop: {
                        visible = false;
                        rAniStop.start();
                        widthAniStop.start();
                    }
                }
                PropertyAnimation{
                    id: rAniStop
                    target: cProBtn
                    property: "radius"
                    duration: 300
                    from: cProBtn.btnHeight/2
                    to: 0
                    onStopped: {
                        Car.switchDriving(!Car.driving)
                        cText.visible = true;
                    }
                }
                PropertyAnimation{
                    id: widthAniStop
                    target: cProBtn
                    property: "width"
                    duration: 300
                    from: cProBtn.btnHeight
                    to: cProBtn.btnWidth
                }
            }

        }
        Item{width: (parent.width - cProBtn.width) / 2;height: parent.height}

    }

    Component.onCompleted: Car.update()
}
