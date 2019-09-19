import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    property string source : ""
    signal imgClick()

    id:root
    radius: width / 2
    border.color: "green"
    Image {
        id: _image
        smooth: true
        visible: false
        anchors.fill: parent
        source: root.source
        sourceSize: Qt.size(parent.size, parent.size)
        antialiasing: true
    }
    Rectangle {
        id: _mask
        color: "yellow"
        anchors.fill: parent
        radius: width / 2
        visible: false
        antialiasing: true
        smooth: true
    }
    OpacityMask {
        id: mask_image
        anchors.fill: _image
        source: _image
        maskSource: _mask
        visible: true
        antialiasing: true
    }

    transform: Rotation {
        origin.x: width/2; origin.y:height/2 ; axis { x: 0; y: 1; z: 0 } angle: 0
        PropertyAnimation on angle {
            id:an
            loops: 1
            from:0
            to: 360
            duration: 1400

        }

    }

    Component.onCompleted: timer.start()

    Timer{
        id:timer
        interval: 5000
        repeat: true
        triggeredOnStart: false
        onTriggered: an.start()

    }
    MouseArea{
        id : mouseArea
        hoverEnabled: true
        anchors.fill: parent
        onClicked: {
            imgClick()
        }
    }

}
