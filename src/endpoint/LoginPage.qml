import QtQuick 2.0
import QtQuick.Controls 2.1
import Qt.labs.settings 1.0
import QtQuick.VirtualKeyboard 2.2

Column{
    signal switchPage(int page)

    width: parent.width
    height: parent.height
    Item{width: parent.width; height: 100}
    spacing: 30

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        width: 80
        height: 50
        text: qsTr("登录")
        font.pixelSize: 45
    }
    Row{
        spacing: 10
        width: parent.width
        Item{id:xx; width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ id:txt; text: "账号："; width: 100; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{
                id:userID
                width: parent.width - txt.width - userIDCheck.width
                height: 30
                text:setting.saveUseID
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                Keys.onReturnPressed: login()
                onPressed: vk.visible=true
            }
            Check{ id:userIDCheck; width: 150; height: 30; emptyTip: "用户名不能为空"; refuseTip: "用户名已存在" }
        }

    }
    Row{
        spacing: 10
        width: parent.width
        Item{width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ text: "密码："; width: 100; font.pixelSize: 20; horizontalAlignment: Text.AlignHCenter}
            TextField{
                id:password
                width: parent.width - txt.width - passwordCheck.width
                height: 30
                text:setting.savePassword
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                Keys.onReturnPressed: login()
                onPressed: vk.visible=true
            }
            Check{ id:passwordCheck; width: 150; height: 30; emptyTip: "密码不能为空"; refuseTip: "密码位数至少为8" }
        }
    }

    Row{
        spacing: 10
        width: parent.width
        Item{width: 20;height: txt.height}
        Item{width: txt.width;height: txt.height}

        Button{
            id:btnlogin
            width: userID.width
            height: 50
            text: "登录"
            onClicked: {
                login()
                if(Account.islogin)
                    switchPage(7)
            }
        }
    }
    Row{
        Item{width: 50;height: txt.height}
        Text {
            text: '<html></style><a href="http://www.baidu.com">没有账号？点击注册</a></html>'
            MouseArea {
               anchors.fill: parent;
               hoverEnabled: true;
               cursorShape:
                   (containsMouse? Qt.PointingHandCursor: Qt.ArrowCursor);
               onClicked: switchPage(5)
           }
        }
    }

    Pop{
        id:pop
        onClosed: {
            userID.focus = true
        }
    }

    Component.onCompleted: userID.focus = true
    Component.onDestruction: {
        setting.saveUseID = userID.text
        setting.savePassword = password.text
    }

    function login()
    {
        var b = Account.login(userID.text, password.text)
        if(b)   {pop.content = "登陆成功"; pop.open();  }
        else    {pop.content = "账号密码错误"; pop.open(); }
    }

    Settings{
        id:setting
        property string saveUseID: ""
        property string savePassword: ""
    }

    InputPanel{
        id:vk
        visible: false
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        onActiveChanged: {
            if(!active) { visible = false; }
        }
    }
}
