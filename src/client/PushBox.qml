import QtQuick 2.0
import UIT.Type 1.0

Rectangle {
    id:root
    property bool active: false
    y:-height

    Image{
        anchors.fill: parent
        source: "images/tipbg3.jpg"
        opacity: 0.7
    }

    Text {
        width: parent.width
        height: parent.height
        horizontalAlignment: Text.left
        verticalAlignment: Text.AlignVCenter

        font.italic: true
        font.pixelSize: 22
        text: MessageList.newMessageSenderName + ": " + MessageList.newMessageContent
    }

    PropertyAnimation on y{
        id:show
        from: -height
        to:0
        duration: 1000
        easing.type: Easing.OutQuart
        running: false
    }
    PropertyAnimation on y{
        id:hide
        from: show.to
        to: show.from
        duration: show.duration
        easing.type: Easing.InQuart
        running: false
        onStopped: MessageList.newMessage = false
    }

    Timer{
        id:tm
        interval: 3000
        repeat: false
        onTriggered: {
            hide.start()
        }
    }

    onActiveChanged:
    {
        if(active)
        {
            if(LayerManager.currentPage !== Type.Page_P2PChat && LayerManager.currentPage !== Type.Page_GroupChat && LayerManager.currentPage !== Type.Page_Message)
                show.start()
            tm.start()
        }
        else
        {
            root.y = -root.height
        }
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            if(MessageList.newMessageIsP2p)
            {
                P2PChat.enterFromNewMessage()
                LayerManager.switchPage(Type.Page_P2PChat)
            }
            else
            {
                GroupChat.enterFromNewMessage()
                LayerManager.switchPage(Type.Page_GroupChat)
            }
        }
    }
}
