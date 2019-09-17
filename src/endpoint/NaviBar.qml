import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Column{
    id:root
    width: 100
    spacing: 2

    signal switchPage(int page);

    Grid {

        Image {
            width: root.width
            height: 190
            source: "/img/NaviPanel/bg1.jpg"

            Column{
                height: parent.height
                width: parent.width
                Row
                {
                    width: parent.width
                    height: 150
                    CircleIcon{
                        id:photo
                        x:20
                        y:20
                        width: 90
                        height: 90
                        //source: "img/icon.jpg"
                        Connections{
                            target: ImageProvider
                            onRefreshImage:
                            {
                                photo.source = ""
                                photo.source = "image://ImgProvider"
                            }
                        }

                        onImgClick: {
                            if(Account.islogin)
                                switchPage(7)
                            else
                                switchPage(6)
                        }
                    }
                    Text {
                        width: parent.width-photo.width
                        height: parent.height-photo.height
                        horizontalAlignment: Text.AlignLeft
                        //verticalAlignment: Text.AlignVCenter
                        id: txt
                        font.pixelSize: 24
                        text: Account.nickname
                        wrapMode: Text.WrapAnywhere
                        padding:10
                        font.bold: true
                    }
                }

                Text {
                    width: parent.width
                    height: parent.height
                    horizontalAlignment: Text.AlignLeft
                    //verticalAlignment: Text.AlignVCenter
                    id: xx
                    font.pixelSize: 18
                    text: Account.signaTure
                    wrapMode: Text.WrapAnywhere
                    padding:10
                    font.bold: true
                    font.italic: true
                    font.underline: true
                }
            }

        }

    }

    Image{
        width: root.width
        source: "/img/CourseMgrPage/line1.png"
    }

    ImageButton{
        width: parent.width
        height: 100
        btText: "我的车"
        btIcon: "images/tab_car.png"
        pressedColor: "#33003300"
        releaseColor: "#33965300"
        onClicked: switchPage(0)
    }
    Image{
        width: root.width
        source: "/img/CourseMgrPage/line1.png"
    }
    ImageButton{
        width: parent.width
        height: 100
        btText: "我的电脑"
        btIcon: "images/pc.png"
        pressedColor: "#33003300"
        releaseColor: "#33965300"
        onClicked: switchPage(1)
    }
    Image{
        width: root.width
        source: "/img/CourseMgrPage/line1.png"
    }
    ImageButton{
        width: parent.width
        height: 100
        btText: "我的手机"
        btIcon: "images/phone.png"
        pressedColor: "#33003300"
        releaseColor: "#33965300"
        onClicked: switchPage(2)
    }
    Image{
        width: root.width
        source: "/img/CourseMgrPage/line1.png"
    }

    ImageButton{
        width: parent.width
        height: 100
        btText: "消息"
        btIcon: "images/chats.png"
        pressedColor: "#33003300"
        releaseColor: "#33965300"
        onClicked: switchPage(3)
    }
    Image{
        width: root.width
        source: "/img/CourseMgrPage/line1.png"
    }

    ImageButton{
        width: parent.width
        height: 100
        btText: "联系人"
        btIcon: "images/contacts.png"
        pressedColor: "#33003300"
        releaseColor: "#33965300"
        onClicked: switchPage(4)
    }

}
