import QtQuick 2.0

Item {
    id:root
    //-1:emptyState, 0:not pass, 1:pass
    property int state: -1
    property string emptyTip: ""
    property string refuseTip: ""


    Image{
        id:img
        source: "img/NewModelPage/yes.png"
        width: 30
        height: 30
        visible: root.state===1
    }

    Text{
        id:txt
        visible: text!==""
        verticalAlignment: Text.AlignHCenter
        color: "red"
    }

    onStateChanged: {
        if(state == -1)
            txt.text = emptyTip
        else if(state == 0)
            txt.text = refuseTip
        else
            txt.text = ""
    }
}
