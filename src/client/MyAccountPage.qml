import QtQuick 2.5
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2
import UIT.Type 1.0

Rectangle{
    id:root
    anchors.fill: parent
    color: "transparent"

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
        Row{
            id:head
            width: parent.width
            height: root.height * 0.2
            spacing: height * 0.05
            CircleIcon{
                id:img
                width: parent.height
                height: width
                onImgClick: picChoose.open()
                source: "file:" + Account.photo
            }
            Column{
                width: parent.width - img.width
                height: parent.height
                Text{
                    id:nk
                    width: parent.width;height: itemHeight
                    font.pixelSize: height * 0.5;font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    text: Account.nickname
                }
                Text {
                    width: parent.width; height: parent.height - nk.height
                    font.bold: true; font.pixelSize: height * 0.25
                    x:10
                    color: "gray"
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    verticalAlignment: Text.AlignVCenter
                    text: Account.signaTure
                }
            }
        }

        Grid{
            id:layout
            rows:7
            columns: 3
            width: parent.width
            height: parent.height - head.height
            verticalItemAlignment: Grid.AlignVCenter
            horizontalItemAlignment: Grid.AlignHCenter
            rowSpacing: 30
            columnSpacing: 0

            Text{ text: "账号："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize:height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter }
            TextField{ width: parent.width - itemWidth*2; height: itemHeight; readOnly: true; text: Account.userID }
            Item{ width: itemWidth; height: itemHeight  }

            Text{ text: "注册时间："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize:height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter }
            TextField{ width: parent.width - itemWidth*2; height: itemHeight; readOnly: true; text: Account.registTime }
            Item{ width: itemWidth; height: itemHeight  }

            Text{ text: "密码："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize:height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter }
            TextField{id:password; width: parent.width - itemWidth*2; height: itemHeight; text: Account.password; validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/} onPressed: if(Proxy.terminalType != Type.Terminal_PC) kb.visible=true }
            Button{ width: height;height:itemHeight ; onClicked: Account.modifyPassword(password.text); Image{width: parent.width;height: parent.height; source: "images/notes.png"} }

            Text{ text: "昵称："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize:height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter }
            TextField{id:nickname; width: parent.width - itemWidth*2; height: itemHeight; text: Account.nickname; onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible=true}
            Button{ width: height;height:itemHeight ; onClicked: Account.modifyNickname(nickname.text); Image{width: parent.width;height: parent.height; source: "images/notes.png"} }

            Text{ text: "签名："; width: itemWidth; height: itemHeight; font.bold: true; font.pixelSize:height * 0.4; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter }
            TextField{id:signaTure; width: parent.width - itemWidth*2; height: itemHeight; text: Account.signaTure; onPressed: if(Proxy.terminalType === Type.Terminal_Vehicle) kb.visible=true}
            Button{ width: height;height:itemHeight ; onClicked: Account.modifySignaTure(signaTure.text); Image{width: parent.width;height: parent.height; source: "images/notes.png"} }

            Item{ width: itemWidth; height: itemHeight  }
            Button{ width: parent.width - itemWidth*2; height: itemHeight; text: "退出账号"; font.bold: true;font.pixelSize: height * 0.4
                onClicked: { Account.logout(); LayerManager.switchPage(Type.Page_Login) }
            }
        }
    }

    Pop{
        width: parent.width
        height: parent.height / 2;
        id:pop }

    FileDialog
    {
        id:picChoose
        title: qsTr("选择头像")
        modality: "WindowModal"
        nameFilters: ["图片文件 (*.jpg *.bmp)"]   //png刷新有点问题，不支持png
        onAccepted: {
            if(!Account.modifyPhoto(picChoose.fileUrl))
            {
                pop.content = "修改头像失败，请注意图片大小应该小于256kb"
                pop.open()
            }
        }
        Component.onCompleted: visible = false
    }


    Keyboard{
        id:kb
        visible: false
        width: parent.width
        height: parent.height * 2 / 5
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        onKey: {
            if(password.focus)
                password.text += content
            else if(nickname.focus)
                nickname.text += content
            else if(signaTure.focus)
                signaTure.text += content
        }
        onDel: {
            if(password.focus)
                password.text = password.text.substring(0, password.text.length - 1)
            else if(nickname.focus)
                nickname.text = nickname.text.substring(0, nickname.text.length - 1)
            else if(signaTure.focus)
                signaTure.text = signaTure.text.substring(0, signaTure.text.length - 1)
        }
    }

}
