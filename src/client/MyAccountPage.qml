import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2
import QtQuick.VirtualKeyboard 2.2

Column {

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
        text: qsTr("我的账号")
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
                width: parent.width - txt.width - modify.width-tail.width
                height: 30
                font.pixelSize: 18
                readOnly: true
                text: Account.userID
            }
        }
    }
    Row{
        spacing: 10
        width: parent.width
        Item{ width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ text: "注册时间："; width: 100; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{
                width: parent.width - txt.width - modify.width-tail.width
                height: 30
                font.pixelSize: 18
                readOnly: true
                text: Account.registTime
            }
        }
    }
    Row{
        spacing: 10
        width: parent.width
        Item{width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ text: "密码："; width: 100; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{
                id:password
                width: parent.width - txt.width - modify.width-tail.width
                height: 30
                font.pixelSize: 18
                text: Account.password
                validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/}
                onPressed: vk.visible=true
            }
            Button{ id:modify;width: 80;height: parent.height;text:"修改"; onClicked: Account.modifyPassword(password.text) }
            Item{id: tail;width: 50;height: txt.height}
        }
    }
    Row{
        spacing: 10
        width: parent.width
        Item{width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ text: "昵称："; width: 100; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{
                id:nickname
                width: parent.width - txt.width - modify.width-tail.width
                height: 30
                font.pixelSize: 18
                text: Account.nickname
                onPressed: vk.visible=true
            }
            Button{ width: 80;height: parent.height;text:"修改";onClicked: Account.modifyNickname(nickname.text) }
        }
    }
    Row{
        spacing: 10
        width: parent.width
        Item{width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ text: "签名："; width: 100; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{
                id:signaTure
                width: parent.width - txt.width - modify.width-tail.width
                height: 30
                font.pixelSize: 18
                text: Account.signaTure
                onPressed: vk.visible=true
            }
            Button{ width: 80;height: parent.height;text:"修改" ;onClicked: Account.modifySignaTure(signaTure.text)}
        }
    }
    Row{
        spacing: 10
        width: parent.width
        Item{width: 30;height: txt.height}
        Row{
            width: parent.width - xx.width
            Text{ text: "头像："; width: 100; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            Button{
                width: 80
                height: 40
                text:"选择"
                onClicked: fileChoose.open()
            }
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
            text: "退出账号"
            onClicked: {
                Account.logout()
                switchPage(6)
            }
        }
    }

    Pop{
        id:pop
    }

    FileDialog
    {
        id:fileChoose
        title: qsTr("选择头像")
        selectFolder: false
        selectMultiple: false
        modality: "WindowModal"
        nameFilters: ["图片文件 (*.jpg *.bmp)"]   //png刷新有点问题，不支持png
        onAccepted: {
            if(!Account.modifyPhoto(fileChoose.fileUrl))
            {
                pop.content = "修改头像失败，请注意图片大小应该小于256kb"
                pop.open()
            }
        }
        Component.onCompleted: visible = false
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
