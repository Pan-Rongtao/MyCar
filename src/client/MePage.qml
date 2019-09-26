import QtQuick 2.5
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2

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
        spacing: 20

        Row{
            id:head
            width: parent.width; height: 100
            spacing: 10
            CircleIcon{
                id:photo
                width: 90; height: 90; source: "images/icon.jpg"
                onImgClick: { picChoose.open() }
                Connections{
                    target:ImageProvider
                    onRefreshImage: {photo.source=""; photo.source="image://ImgProvider"}
                }
            }
            Column{
                width: parent.width - photo.width
                height: parent.height
                Text{
                    id:nk
                    width: parent.width;height: 30
                    font.pixelSize: 24;font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    text: "Pan.瞳"
                }
                Text {
                    width: parent.width
                    height: parent.height - nk.height
                    font.bold: true; font.pixelSize: 14
                    color: "gray"
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    x:0
                    verticalAlignment: Text.AlignVCenter
                    text: "该用户很懒，懒得签名！abadafsdgadgadgadgafaoeifhaefaoeihfo"
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

            Text{ text: "账号："; width: item0Width; font.bold: true; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{ width: parent.width - item0Width - item2Width; height: item0Height; readOnly: true; text: Account.userID }
            Item{ width: item2Width; height: item0Height  }

            Text{ text: "注册时间："; width: item0Width; font.bold: true; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{ width: parent.width - item0Width - item2Width; height: item0Height; readOnly: true; text: Account.registTime }
            Item{ width: item2Width; height: item0Height  }

            Text{ text: "密码："; width: item0Width; font.bold: true; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{id:password; width: parent.width - item0Width - item2Width; height: item0Height; text: Account.password; validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/} }
            Button{ width: item2Width;height:item0Height ;text:"修改"; onClicked: Account.modifyPassword(password.text) }

            Text{ text: "昵称："; width: item0Width; font.bold: true; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{id:nickname; width: parent.width - item0Width - item2Width; height: item0Height; text: Account.nickname; validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/} }
            Button{ width: item2Width;height:item0Height ;text:"修改"; onClicked: Account.modifyNickname(nickname.text) }

            Text{ text: "签名："; width: item0Width; font.bold: true; font.pixelSize:20; horizontalAlignment: Text.AlignHCenter }
            TextField{id:signaTure; width: parent.width - item0Width - item2Width; height: item0Height; text: Account.nickname; validator: RegExpValidator{regExp:/[0-9A-Za-z]{20}$/} }
            Button{ width: item2Width;height:item0Height ;text:"修改"; onClicked: Account.modifySignaTure(signaTure.text) }


            Item{ width: item0Width; height: item0Height  }
            Rectangle{

            }

            Button{ width: parent.width - item0Width - item2Width; height: 50;
                text: "退出账号";
                onClicked: { Account.logout(); switchPage(6) }
            }
        }
    }

    Pop{ id:pop }

    FileDialog
    {
        id:picChoose
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
}
