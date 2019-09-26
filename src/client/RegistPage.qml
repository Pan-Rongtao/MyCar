import QtQuick 2.5
import QtQuick.Controls 2.1

Rectangle{
    id:root
    width: parent.width
    height: parent.height
    color: "#00000000"

    signal naviToLogin()
    property bool bRegist: false
    property int item0Width: 100
    property int item2Width: 80
    property int item0Height: 30

    Column{
        width: parent.width
        height: parent.height

        Text {
            id:head
            text: qsTr("注册")
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
                onTextChanged: {userIDCheck.state = text==="" ? -1 : (Account.isRegisted(text) ? 0 : 1)}
            }
            Check{ id:userIDCheck; width: item2Width; height: item0Height; emptyTip: "账号不能为空"; refuseTip: "账号已存在" }

            Text{ text: "密码："; width: item0Width; font.bold: true; font.pixelSize: 20; horizontalAlignment: Text.AlignHCenter}
            TextField{
                id:password
                width: parent.width - item0Width - item2Width; height: item0Height
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                onTextChanged: {passwordCheck.state = text==="" ? -1 : (text.length < 8 ? 0 : 1)}
            }
            Check{ id:passwordCheck; width: item2Width; height: item0Height; emptyTip: "密码不能为空"; refuseTip: "密码位数至少为8" }

            Text{ text: "重复密码："; width: item0Width; font.bold: true; font.pixelSize: 20; horizontalAlignment: Text.AlignHCenter}
            TextField{
                width: parent.width - item0Width - item2Width; height: item0Height
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                onTextChanged: {passwordAgainCheck.state = text==="" ? -1 : (text!==password.text ? 0 : 1)}
            }
            Check{ id:passwordAgainCheck; width: item2Width; height: item0Height; emptyTip: "密码不能为空"; refuseTip: "两次输入的密码不相同" }

            Text{ text: "昵称："; width: item0Width; font.bold: true; font.pixelSize: 20; horizontalAlignment: Text.AlignHCenter}
            TextField{
                id:nickname
                width: parent.width - item0Width - item2Width; height: item0Height
                onTextChanged: {nicknameCheck.state = text==="" ? -1 : 1}
            }
            Check{ id:nicknameCheck; width: item2Width; height: item0Height; emptyTip: "昵称不能为空"; refuseTip: "" }

            Rectangle{width: item0Width;height: item0Height}
            Button{
                width: parent.width - item0Width - item2Width; height: 50
                text: "注册"
                font.bold: true
                font.pixelSize: 28
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
            Rectangle{width: item2Width;height: item0Height}


            Rectangle{width: item0Width;height: item0Height}
            Text {
                text: '<html></style><a href="http://www.baidu.com">已有账号？点击登录</a></html>'
                MouseArea {
                   anchors.fill: parent;
                   hoverEnabled: true;
                   cursorShape:(containsMouse? Qt.PointingHandCursor: Qt.ArrowCursor);
                   onClicked: switchPage(6)
               }
            }
            Rectangle{width: item2Width;height: item0Height}
        }

    }


    Pop{ id:pop; onClosed: { userID.focus = true; if(bRegist) switchPage(6) } }
    Component.onCompleted: userID.focus = true
}
