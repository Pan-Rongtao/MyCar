import QtQuick 2.5
import QtQuick.Controls 2.1
import Qt.labs.settings 1.0
import UIT.Type 1.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    property int itemWidth: root.width * 0.12
    property int itemHeight: root.height * 0.075
    property bool loginSuccess: false

    MouseArea{
        anchors.fill: parent
        onPressed: kb.visible = false
    }
    Column{
        width: parent.width
        height: parent.height
        spacing: height * 0.035
        Text {
            id:head
            text: "登录"
            width: parent.width
            height: root.height * 0.1
            font.pointSize: height * 1 / 3
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
            rowSpacing: parent.spacing

            Text{ text: "账号："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize: height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter }
            TextField{
                id:userID
                width: parent.width - itemWidth * 2; height: itemHeight
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                text:setting.saveUseID
                Keys.onReturnPressed: login()
                onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible = true
            }
            Button{ width: itemWidth; height: itemHeight; opacity: 0.1; onClicked: pxy.visible = !pxy.visible; }

            Text{ text: "密码："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize: height * 0.4; verticalAlignment: Text.AlignVCenter;horizontalAlignment: Text.AlignHCenter }
            TextField{
                id:password
                width: parent.width - itemWidth * 2; height: itemHeight
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                text:setting.savePassword
                Keys.onReturnPressed: login()
                onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible = true
            }
            Rectangle{ width: itemWidth; height: itemHeight }

            Rectangle{width: itemWidth;height: itemHeight}
            Button{
                width: parent.width - itemWidth * 2; height: itemHeight
                text: "登录"; font.bold: true; font.pixelSize: height * 0.4
                onClicked: login()
            }
            Rectangle{width: itemWidth;height: itemHeight}

            Rectangle{width: itemWidth;height: itemHeight}
            Text {
                text: '<html></style><a href="http://www.baidu.com">没有账号？点击注册</a></html>'
                MouseArea {
                   anchors.fill: parent;
                   hoverEnabled: true;
                   cursorShape:(containsMouse? Qt.PointingHandCursor: Qt.ArrowCursor);
                   onClicked: LayerManager.currentPage = Type.Page_Regist
               }
            }
            Rectangle{width: itemWidth;height: itemHeight}
        }
    }

    Pop{
        id:pop
        width: parent.width
        height: parent.height / 2
        onClosed:
        {
            userID.focus = true
            if(loginSuccess)
                LayerManager.switchPage(Type.Page_Account)
        }
    }

    Component.onCompleted: userID.focus = true
    Component.onDestruction: {
        setting.saveUseID = userID.text
        setting.savePassword = password.text
    }

    function login()
    {
        loginSuccess = Account.login(userID.text, password.text)
        pop.content = loginSuccess ? "登陆成功，正在加载..." : "账号密码错误"
        pop.open()
    }

    Settings{ id:setting; property string saveUseID: ""; property string savePassword: "" }

    Keyboard{
        id:kb
        visible: false
        width: parent.width
        height: parent.height * 2 / 5
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        onKey: {
            if(userID.focus)
                userID.text += content
            else if(password.focus)
                password.text += content
        }
        onDel: {
            if(userID.focus)
                userID.text = userID.text.substring(0, userID.text.length - 1)
            else if(password.focus)
                password.text = password.text.substring(0, password.text.length - 1)
        }
    }
    Rectangle{
        id: pxy
        visible: false
        anchors.fill: parent

        Column{
            width: parent.width
            height: parent.height
            spacing: height * 0.035
            Text {
                id:xx
                text: "设置服务器"
                width: parent.width
                height: root.height * 0.1
                font.pointSize: height * 1 / 3
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Grid{
                id:xxlayout
                rows:6
                columns: 3
                width: parent.width
                height: parent.height - head.height
                verticalItemAlignment: Grid.AlignVCenter
                horizontalItemAlignment: Grid.AlignHCenter
                rowSpacing: parent.spacing

                Text{ text: "IP："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize: height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter }
                TextField{
                    id:ip
                    width: parent.width - itemWidth * 2; height: itemHeight
                    text:"24l0x21424.qicp.vip"
                    Keys.onReturnPressed: login()
                    onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible = true
                }
                Rectangle{ width: itemWidth; height: itemHeight }

                Text{ text: "端口1："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize: height * 0.4; verticalAlignment: Text.AlignVCenter;horizontalAlignment: Text.AlignHCenter }
                TextField{
                    id:port1
                    width: parent.width - itemWidth * 2; height: itemHeight
                    validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                    text:"50074"
                    Keys.onReturnPressed: login()
                    onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible = true
                }
                Rectangle{ width: itemWidth; height: itemHeight }

                Text{ text: "端口2："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize: height * 0.4; verticalAlignment: Text.AlignVCenter;horizontalAlignment: Text.AlignHCenter }
                TextField{
                    id:port2
                    width: parent.width - itemWidth * 2; height: itemHeight
                    validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                    text:"51191"
                    Keys.onReturnPressed: login()
                    onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible = true
                }
                Rectangle{ width: itemWidth; height: itemHeight }

                Rectangle{width: itemWidth;height: itemHeight}
                Button{
                    width: parent.width - itemWidth * 2; height: itemHeight
                    text: "连接"; font.bold: true; font.pixelSize: height * 0.4
                    onClicked: Proxy.connectToServer(ip.text, Number(port1.text), Number(port2.text));
                }
                Rectangle{width: itemWidth;height: itemHeight}

            }
        }
    }
}
