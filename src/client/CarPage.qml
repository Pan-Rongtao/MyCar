import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    property int itemWidth: root.width * 0.2
    property int itemHeight: root.height * 0.045

    Column{
        width: parent.width
        height: parent.height
        spacing: height * 0.015
        Text {
            id:head
            text: "我的车"
            width: parent.width
            height: root.height * 0.1
            font.pointSize: height * 1 / 3
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            property int value: Car.driving ? 200 : 0
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            width: parent.width / 4
            height: itemHeight
            text: value + "km/h"
            font.pixelSize: height * 0.6
            PropertyAnimation on value {
                id:up
                from: 0
                to: 200
                duration:1000 * 6
                easing.type: Easing.OutQuad
                running: false
            }
            PropertyAnimation on value {
                id:down
                from: up.to
                to: up.from
                duration:up.duration
                easing.type: Easing.InQuart
                running: false
            }
        }

        GroupBox{
            id:carInfoGroup
            title: "车辆信息"
            width: parent.width
            height: itemHeight * 7
            Row{
                width: parent.width
                height: parent.height
                Column{
                    x:20
                    width: parent.width / 2
                    height: parent.height
                    spacing: 0
                    Text{ text: "剩余油量：" + Car.availableFuel + "%"; width: parent.width; height: itemHeight;  horizontalAlignment: Text.AlignLeft; verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6}
                    Text{ text: "平均油耗：" + Car.averageFuel + "L/100km"; width: parent.width; height: itemHeight;  horizontalAlignment: Text.AlignLeft; verticalAlignment: Text.AlignVCenter;font.pixelSize: height * 0.6 }
                    Text{ text: "总行驶里程：" + Car.totalKm + "km"; width: parent.width; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                    Text{ text: "小计里程A：" + Car.subKmA + "km"; width: parent.width; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                    Text{ text: "小计里程B：" + Car.subKmB + "km"; width: parent.width; height: itemHeight; horizontalAlignment: Text.AlignLeft; verticalAlignment: Text.AlignVCenter;font.pixelSize: height * 0.6 }
                    }
                Column{
                    width: parent.width / 2
                    height: parent.height
                    Text{ text: "熄火地点："; width: parent.width; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6}
                    Image{ source: "images/parking.jpg" }
                }
            }
        }

        GroupBox{
            title: "车辆控制"
            width: carInfoGroup.width
            height: itemHeight * 8
            Grid{
                width: parent.width
                height: parent.height
                rows: 7
                columns:4
                rowSpacing: 10
                columnSpacing: 20
                Text { text: "左前车门："; width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                ToggleButton{ width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; leftString: "打开"; rightString: "关闭"; toggle:Car.leftFrontDoor; onToggled: Car.switchLeftFrontDoor(on) }

                Text { text: "右前车门："; width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                ToggleButton{ width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; toggle:Car.rightFrontDoor; leftString: "打开" ;rightString: "关闭"; onToggled: Car.switchRightFrontDoor(on) }

                Text { text: "左后车门："; width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                ToggleButton{  width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; leftString: "打开"; rightString: "关闭"; toggle:Car.leftRearDoor; onToggled: Car.switchLeftRearDoor(on) }

                Text { text: "右后车门："; width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                ToggleButton{ width: (parent.width - parent.columnSpacing * 4) / 4;height: itemHeight; leftString: "打开";rightString: "关闭"; toggle:Car.rightRearDoor; onToggled: Car.switchRightRearDoor(on) }

                Text { text: "左前车窗：";  width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                ToggleButton{ width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; leftString: "打开"; rightString: "关闭"; toggle:Car.leftFrontWindow; onToggled: Car.switchLeftFrontWindow(on) }

                Text { text: "右前车窗：";  width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                ToggleButton{ width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; leftString: "打开"; rightString: "关闭"; toggle:Car.rightFrontWindow; onToggled: Car.switchRightFrontWindow(on) }

                Text { text: "左后车窗：";  width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                ToggleButton{ width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; leftString: "打开"; rightString: "关闭"; toggle:Car.leftRearWindow; onToggled: Car.switchLeftRearWindow(on) }

                Text { text: "右后车窗：";  width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                ToggleButton{ width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; leftString: "打开"; rightString: "关闭"; toggle:Car.rightRearWindow; onToggled: Car.switchRightRearWindow(on) }

                Text { text: "空调开关："; width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                ToggleButton{ width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; leftString: "打开"; rightString: "关闭"; toggle:Car.AC; onToggled: Car.switchAC(on) }

                Text { text: "空调温度："; width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight; horizontalAlignment: Text.AlignLeft;verticalAlignment: Text.AlignVCenter; font.pixelSize: height * 0.6 }
                Row{
                    width: (parent.width - parent.columnSpacing * 4) / 4; height: itemHeight
                    Slider{ id:slider; width:itemWidth; height: itemHeight; minimumValue: 18; maximumValue: 30; stepSize: 1;updateValueWhileDragging: false
                        property bool firstTime: true
                        value: Car.ACTemp
                        onValueChanged:{
                            if(!firstTime)
                                Car.switchACTemp(value)
                            firstTime = false
                        }
                    }
                    Text { height: itemHeight; text: slider.value;verticalAlignment: Text.AlignVCenter}

                }
            }

        }

        Grid{
            width: parent.width
            height: itemHeight * 2
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
                    font.pixelSize: parent.height * 0.5
                    text: Car.driving ? "熄火" : "启动"
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if (rAniStart.running || rAniStop.running) return
                        cText.visible = false;
                        rAniStart.start();
                        widthAniStart.start();
                        if(Car.driving)
                            down.start()
                        else
                            up.start()
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
