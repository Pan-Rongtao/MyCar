import QtQuick 2.5
import QtQuick.Controls 2.1
import Qt.labs.settings 1.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    signal naviToRegist()
    signal loginResult(bool success)
    property int item0Width: 100
    property int item2Width: 80
    property int item0Height: 30

    Column{
        width: parent.width
        height: parent.height

        Text {
            id:head
            text: qsTr("登录")
            width: parent.width
            height: 100
            font.pixelSize: 45
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Grid{
            id:layout
            rows:6
            columns: 3
            width: parent.width
            height: parent.height - head.height
            verticalItemAlignment: Grid.AlignVCenter
            horizontalItemAlignment: Grid.AlignHCenter
            rowSpacing: 30
            columnSpacing: 0

            Text{ text: "账号："; width: item0Width; font.bold: true; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{
                id:userID
                width: parent.width - item0Width - item2Width; height: item0Height
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                text:setting.saveUseID
                Keys.onReturnPressed: login()
            }
            Rectangle{ width: item2Width; height: item0Height  }

            Text{ text: "密码："; width: item0Width; font.bold: true; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{
                id:password
                width: parent.width - item0Width - item2Width; height: item0Height
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                text:setting.savePassword
                Keys.onReturnPressed: login()
            }
            Rectangle{ width: item2Width; height: item0Height }

            Rectangle{width: item0Width;height: item0Height}
            Button{
                width: parent.width - item0Width - item2Width; height: 50
                text: "登录"; font.bold: true; font.pixelSize: 28
                onClicked:  loginResult(login())
            }
            Rectangle{width: item2Width;height: item0Height}

            Rectangle{width: item0Width;height: item0Height}
            Text {
                text: '<html></style><a href="http://www.baidu.com">没有账号？点击注册</a></html>'
                MouseArea {
                   anchors.fill: parent;
                   hoverEnabled: true;
                   cursorShape:(containsMouse? Qt.PointingHandCursor: Qt.ArrowCursor);
                   onClicked: naviToRegist()
               }
            }
            Rectangle{width: item2Width;height: item0Height}
        }
    }

    Pop{ id:pop; onClosed: userID.focus = true }

    Component.onCompleted: userID.focus = true
    Component.onDestruction: {
        setting.saveUseID = userID.text
        setting.savePassword = password.text
    }

    function login()
    {
        var b = Account.login(userID.text, password.text)
        pop.content = b ? "登陆成功" : "账号密码错误"
        pop.open()
        return b;
    }

    Settings{ id:setting; property string saveUseID: ""; property string savePassword: "" }

}
