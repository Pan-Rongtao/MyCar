import QtQuick 2.5
import QtQuick.Controls 2.1
import UIT.Type 1.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

    property bool bRegist: false
    property int itemWidth: root.width * 0.15
    property int itemHeight: root.height * 0.075

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
            text: "注册"
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
                onTextChanged: {userIDCheck.state = text==="" ? -1 : (Account.isRegisted(text) ? 0 : 1)}
                onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible = true
            }
            Check{ id:userIDCheck; width: itemWidth; height: itemHeight; emptyTip: "账号不能为空"; refuseTip: "账号已存在" }

            Text{ text: "密码："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize: height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter}
            TextField{
                id:password
                width: parent.width - itemWidth * 2; height: itemHeight
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                onTextChanged: {passwordCheck.state = text==="" ? -1 : (text.length < 8 ? 0 : 1)}
                onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible = true
            }
            Check{ id:passwordCheck; width: itemWidth; height: itemHeight; emptyTip: "密码不能为空"; refuseTip: "密码至少8位" }

            Text{ text: "重复密码："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize: height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter}
            TextField{
                id:passwordAgain
                width: parent.width - itemWidth * 2; height: itemHeight
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                onTextChanged: {passwordAgainCheck.state = text==="" ? -1 : (text!==password.text ? 0 : 1)}
                onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible = true
            }
            Check{ id:passwordAgainCheck; width: itemWidth; height: itemHeight; emptyTip: "密码不能为空"; refuseTip: "两次输入的密码不相同" }

            Text{ text: "昵称："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize: height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter}
            TextField{
                id:nickname
                width: parent.width - itemWidth * 2; height: itemHeight
                onTextChanged: {nicknameCheck.state = text==="" ? -1 : 1}
                onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible = true
            }
            Check{ id:nicknameCheck; width: itemWidth; height: itemHeight; emptyTip: "昵称不能为空"; refuseTip: "" }

            Rectangle{width: itemWidth;height: itemHeight}
            Button{
                width: parent.width - itemWidth * 2; height: itemHeight
                text: "注册"
                font.bold: true
                font.pixelSize: height * 0.4
                onClicked: {
                    if(userIDCheck.state != 1 || passwordCheck.state !=1 || passwordAgainCheck.state != 1 || nicknameCheck.state != 1)
                    {
                        pop.content = "请检查注册信息是否合规"
                    }
                    else
                    {
                        bRegist = Account.regist(userID.text, password.text, nickname.text);
                        pop.content = bRegist ? "注册成功" : "注册失败，可能因为账号已存在"
                    }
                    pop.open()
                }
            }
            Rectangle{width: itemWidth;height: itemHeight}


            Rectangle{width: itemWidth;height: itemHeight}
            Text {
                text: '<html></style><a href="http://www.baidu.com">已有账号？点击登录</a></html>'
                MouseArea {
                   anchors.fill: parent;
                   hoverEnabled: true;
                   cursorShape:(containsMouse? Qt.PointingHandCursor: Qt.ArrowCursor);
                   onClicked: LayerManager.switchPage(Type.Page_Login)
               }
            }
            Rectangle{width: itemWidth; height: itemHeight}
        }

    }

    Pop{ id:pop; onClosed: { userID.focus = true; if(bRegist) LayerManager.switchPage(Type.Page_Login) } }
    Component.onCompleted: userID.focus = true


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
            else if(passwordAgain.focus)
                passwordAgain.text += content
            else if(nickname.focus)
                nickname.text += content
        }
        onDel: {
            if(userID.focus)
                userID.text = userID.text.substring(0, userID.text.length - 1)
            else if(password.focus)
                password.text = password.text.substring(0, password.text.length - 1)
            else if(passwordAgain.focus)
                passwordAgain.text = passwordAgain.text.substring(0, passwordAgain.text.length - 1)
            else if(nickname.focus)
                nickname.text = nickname.text.substring(0, nickname.text.length - 1)
        }
    }

}
