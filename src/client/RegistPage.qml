import QtQuick 2.5
import QtQuick.Controls 2.1
import QtQuick.VirtualKeyboard 2.2

Column{
    signal switchPage(int page)

    property bool bRegist: false

    width: parent.width
    height: parent.height
    Item{width: parent.width; height: 100}
    spacing: 30
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        width: 80
        height: 50
        text: qsTr("注册")
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
                placeholderText: "Input The UserID"
                width: parent.width - txt.width - userIDCheck.width
                height: 30
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                onTextChanged: {userIDCheck.state = userID.text==="" ? -1 : (Account.isRegisted(userID.text) ? 0 : 1); tip.visible=false}
                onPressed: vk.visible=true
            }
            Check{ id:userIDCheck; width: 150; height: 30; emptyTip: "账号不能为空"; refuseTip: "账号已存在" }
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
                placeholderText: "Input The Password"
                width: parent.width - txt.width - passwordCheck.width
                height: 30
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                onTextChanged: {passwordCheck.state = password.text==="" ? -1 : (password.length<8 ? 0 : 1); tip.visible=false}
                onPressed: vk.visible=true
            }
            Check{ id:passwordCheck; width: 150; height: 30; emptyTip: "密码不能为空"; refuseTip: "密码位数至少为8" }
        }
    }
    Row{
        spacing: 10
        width: parent.width
        Item{width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ text: "重复密码："; width: 100 ;font.pixelSize: 20; horizontalAlignment: Text.AlignHCenter }
            TextField{
                id:passwordAgain
                placeholderText: "Confirm The UserID"
                width: parent.width - txt.width - passwordAgainCheck.width
                height: 30
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                onTextChanged: {passwordAgainCheck.state = passwordAgain.text==="" ? -1 : (passwordAgain.text!==password.text ? 0 : 1); tip.visible=false}
                onPressed: vk.visible=true
            }
            Check{ id:passwordAgainCheck; width: 150; height: 30; emptyTip: "密码不能为空"; refuseTip: "两次输入的密码不相同" }
        }
    }
    Row{
        spacing: 10
        width: parent.width
        Item{width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ text: "昵称：";width: 100;font.pixelSize: 20;horizontalAlignment: Text.AlignHCenter;}
            TextField{
                id:nickname
                placeholderText: "Input The Nickname"
                width: parent.width - txt.width - nicknameCheck.width
                height: 30
                onTextChanged: {nicknameCheck.state = nickname.text==="" ? -1 : 1; tip.visible=false}
                onPressed: vk.visible=true
            }
            Check{ id:nicknameCheck; width: 150; height: 30; emptyTip: "昵称不能为空"; refuseTip: "" }
        }
    }
    Row{
        spacing: 10
        width: parent.width
        Item{width: 20;height: txt.height}
        Item{width: txt.width;height: txt.height}

        Button{
            width: userID.width
            height: 50
            text: "注册"
            onClicked: {
                if(userIDCheck.state != 1 || passwordCheck.state !=1 || passwordAgainCheck.state != 1 || nicknameCheck.state != 1)
                {
                    pop.content = "请检查注册信息是否合规"
                    pop.open()
                }
                else
                {
                    tip.visible=false
                    bRegist = Account.regist(userID.text, password.text, nickname.text);
                    pop.content = bRegist ? "注册成功" : "注册失败，可能因为账号已存在"
                    pop.open()
                }
            }
        }
        Text { id: tip;text: qsTr("请检查注册信息是否合规");color: "red";visible: false;}
    }

    Row{
        Item{width: 50;height: txt.height}
        Text {
            text: '<html></style><a href="http://www.baidu.com">已有账号？点击登录</a></html>'
            MouseArea {
               anchors.fill: parent;
               hoverEnabled: true;
               cursorShape:
                   (containsMouse? Qt.PointingHandCursor: Qt.ArrowCursor);
               onClicked: switchPage(6)
           }
        }
    }

    Pop{
        id:pop
        onClosed: {
            userID.focus = true
            if(bRegist)
                switchPage(6)
        }
    }

    Component.onCompleted: {
        userID.focus = true
    }
    onVisibleChanged: userID.focus = true

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
