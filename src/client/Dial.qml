import QtQuick 2.2
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
Dial {
    id:dial;
    Text {
        anchors.centerIn: parent;
        id: value_text;
        color:"white";
        font.family: "方正兰亭超细黑简体";
        font.bold: true;
        font.pixelSize: 26;
        text: dial.value.toString();
    }

    tickmarksVisible:true;
    stepSize: 0.5;                  //拨动一次的大小
    maximumValue: 31;
    minimumValue: 16;
    width: 200;
    height: 200;

    style: DialStyle {
        id:d_style;

        //outerRadius只读参数（半径大小）
////////////////////////一个大刻度之间的小刻度
        minorTickmarkCount:10       //大刻度之间小刻度数量
        minorTickmarkInset:0;       //距离外径（outerRadius）的距离（正时向内靠近）
        minorTickmark:Rectangle{
            color:"blue";
            implicitWidth: 5;       //大小有固定需要用implicitWidth才能改变
            implicitHeight: 5;
            radius: implicitWidth/2;
            MouseArea{
                anchors.fill: parent;
                onClicked: {
                     console.log("value"+styleData.value);//点击刻度读取刻度对应的值
                     console.log("index"+styleData.index);//点击刻度读取刻度对应的序号
                     console.log(valueToAngle(styleData.value))//值对应的角度
                }

            }
        }

/////////////////////////刻度（小刻度的分割点）
        tickmark:Rectangle{
            implicitWidth: 10;
            implicitHeight: 10;
            color: "yellow";
            radius: implicitWidth/2;
            MouseArea{
                anchors.fill: parent;
                onClicked: {
                     console.log("value"+styleData.value);//点击刻度读取刻度对应的值
                     console.log("index"+styleData.index);//点击刻度读取刻度对应的序号
                     console.log(valueToAngle(styleData.value))//计算值对应的角度可以用来绘画外面的圆圈
                }

            }

        }
        tickmarkInset: -5;          //距离外径（outerRadius）的距离（正时向内靠近）
        tickmarkStepSize:2;         //和tickmarkCount（只读）对应
                                    //tickmarkCount = （maximumValue-minimumValue）/ tickmarkStepSize
//////////////////////////刻度
        tickmarkLabel:Rectangle{
            color: "red";
            implicitWidth: 5;
            implicitHeight: 5;
            radius: implicitWidth/2;

        }
        labelStepSize :2;
        labelInset:-10;
////////////////////////转动时的旋钮
        handle :Rectangle{
            color:"green";
            height: 20;
            width: 20;
            radius: width/2;
        }
////////////////////////背景
        background: Rectangle{
            color:"gray";
            radius: width/2;

        }

    }
}
