import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Column{
    signal switchToRegPage()

    width: parent.width
    height: parent.height
    Item{width: parent.width; height: 20}
    spacing: 20

    Text {
        id:head
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        width: 80
        height: 50
        text: qsTr("我的车")
        font.pixelSize: 45
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
        width: parent.width - 10
        height: 100
        GridLayout{
            columns:2
                Row{
                    width: parent.width /2
                    Text{ id:txt; text: "剩余油量："; width: 100;  horizontalAlignment: Text.AlignLeft }
                    Text {text: Car.availableFuel + "%"  }
                }
                Row{
                    width: parent.width /2
                    Text{ text: "平均油耗："; width: 100;  horizontalAlignment: Text.AlignLeft }
                    Text {text: Car.averageFuel + "L/100km"  }
                }
                Row{
                    width: parent.width /2
                    Text{ text: "总行驶里程："; width: 100;  horizontalAlignment: Text.AlignLeft }
                    Text {text: Car.totalKm + "km"  }
                }
                Row{
                    width: parent.width /2
                    Text{ text: "小计里程A："; width: 100;  horizontalAlignment: Text.AlignLeft }
                    Text {text: Car.subKmA + "km" }
                }
                Row{
                    width: parent.width /2
                    Text{ text: "小计里程B："; width: 100;  horizontalAlignment: Text.AlignLeft }
                    Text {text: Car.subKmB + "km" }
                }
            }
        }

    GroupBox{
        title: "车辆控制"
        width: carInfoGroup.width
        height: 200

        GridLayout{
            columns:2
            Row{
                spacing: 10
                Text { id: t;height: 26; text: "左前车门："; verticalAlignment: Text.AlignVCenter;  }
                ToggleButton{
                    width: 80
                    height: t.height
                    toggle:Car.leftFrontDoor
                    leftString: qsTr("打开")
                    rightString: qsTr("关闭")
                    onToggled: {
                        Car.switchLeftFrontDoor(on)
                    }
                }
            }

            Row{
                spacing: 10
                Text { height: 26; text: "右前车门："; verticalAlignment: Text.AlignVCenter;  }
                ToggleButton{
                    width: 80
                    height: t.height
                    toggle:Car.rightFrontDoor
                    leftString: qsTr("打开")
                    rightString: qsTr("关闭")
                    onToggled: {
                        Car.switchRightFrontDoor(on)
                    }
                }
            }
            Row{
                spacing: 10
                Text { height: 26; text: "左后车门："; verticalAlignment: Text.AlignVCenter;  }
                ToggleButton{
                    width: 80
                    height: t.height
                    toggle:Car.leftRearDoor
                    leftString: qsTr("打开")
                    rightString: qsTr("关闭")
                    onToggled: {
                        Car.switchLeftRearDoor(on)
                    }
                }
            }
            Row{
                spacing: 10
                Text { height: 26; text: "右后车门："; verticalAlignment: Text.AlignVCenter;  }
                ToggleButton{
                    width: 80
                    height: t.height
                    toggle:Car.rightRearDoor
                    leftString: qsTr("打开")
                    rightString: qsTr("关闭")
                    onToggled: {
                        Car.switchRightRearDoor(on)
                    }
                }
            }
            Row{
                spacing: 10
                Text { height: 26; text: "左前车窗："; verticalAlignment: Text.AlignVCenter;  }
                ToggleButton{
                    width: 80
                    height: t.height
                    toggle:Car.leftFrontWindow
                    leftString: qsTr("打开")
                    rightString: qsTr("关闭")
                    onToggled: {
                        Car.switchLeftFrontWindow(on)
                    }
                }
            }
            Row{
                spacing: 10
                Text { height: 26; text: "右前车窗："; verticalAlignment: Text.AlignVCenter;  }
                ToggleButton{
                    width: 80
                    height: t.height
                    toggle:Car.rightFrontWindow
                    leftString: qsTr("打开")
                    rightString: qsTr("关闭")
                    onToggled: {
                        Car.switchRightFrontWindow(on)
                    }
                }
            }
            Row{
                spacing: 10
                Text { height: 26; text: "左后车窗："; verticalAlignment: Text.AlignVCenter;  }
                ToggleButton{
                    width: 80
                    height: t.height
                    toggle:Car.leftRearWindow
                    leftString: qsTr("打开")
                    rightString: qsTr("关闭")
                    onToggled: {
                        Car.switchLeftRearWindow(on)
                    }
                }
            }
            Row{
                spacing: 10
                Text { height: 26; text: "右后车窗："; verticalAlignment: Text.AlignVCenter;  }
                ToggleButton{
                    width: 80
                    height: t.height
                    toggle:Car.rightRearWindow
                    leftString: qsTr("打开")
                    rightString: qsTr("关闭")
                    onToggled: {
                        Car.switchRightRearWindow(on)
                    }
                }
            }

            Row{
                spacing: 10
                Text { height: 26; text: "空调开关："; verticalAlignment: Text.AlignVCenter;  }
                ToggleButton{
                    width: 80
                    height: t.height
                    toggle:Car.AC
                    leftString: qsTr("打开")
                    rightString: qsTr("关闭")
                    onToggled: {
                        Car.switchAC(on)
                    }
                }
            }
            Row{
                spacing: 10
                Text { height: 26; text: "空调温度："; verticalAlignment: Text.AlignVCenter;  }
                Slider{
                    id:slider
                    width:80
                    height: t.height
                    value: Car.ACTemp
                    minimumValue: 18
                    maximumValue: 30
                    stepSize: 1
                    onValueChanged: Car.switchACTemp(value)
                }
                Text {height: 26; text: slider.value;verticalAlignment: Text.AlignVCenter}
            }
        }

    }

    ToggleButton{
        width: 150
        height: 80
        toggle:Car.driving
        leftString: qsTr("启动")
        rightString: qsTr("停车")
        onToggled: {
            Car.switchDriving(on)
        }
    }

}
