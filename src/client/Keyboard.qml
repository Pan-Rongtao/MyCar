import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle {
    id:root
    width: parent.width
    height: parent.height
    color:"#ff000000"

    property bool lowCase: true
    property bool numCase: false
    property int itemWidth: (main.width - row0.spacing * 9) /  11;
    property int itemHeight: (main.height - col.spacing * 3) /  4;

    signal key(string content)
    signal del()

    Rectangle{
        id:main
        anchors.fill: parent
        anchors.margins: 10
        color: "transparent"
        Column{
            id:col
            spacing: 3
            width: parent.width
            height: parent.height
            Row{
                id:row0
                spacing: 3
                Repeater{
                    id:rp0
                    model: ["q", "w", "e", "r", "t", "y", "u", "i", "o", "p"]
                    Key{
                        width: itemWidth
                        height: itemHeight
                        content: modelData
                        onClick: key(content)
                    }
                }
                Key{
                    width: itemWidth
                    height: itemHeight
                    content: "DEL"
                    onClick: del()
                }
            }

            Row{
                id:row1
                spacing: 3
                x:itemWidth / 2
                Repeater{
                    id:rp1
                    model: ["a", "s", "d", "f", "g", "h", "j", "k", "l"]
                    Key{
                        width: itemWidth
                        height: itemHeight
                        content: modelData
                        onClick: key(content)
                    }
                }
                Key{
                    width: itemWidth
                    height: itemHeight
                    content: "RT"
                }
            }

            Row{
                id:row2
                spacing: 3
                Key{
                    width: itemWidth
                    height: itemHeight
                    content: "Cap"
                    onClick: {
                        lowCase = !lowCase
                        switchCase(numCase, lowCase)
                    }
                }
                Repeater{
                    id:rp2
                    model: ["z", "x", "c", "v", "b", "n", "m", ",", "."]
                    Key{
                        width: itemWidth
                        height: itemHeight
                        content: modelData
                        onClick: key(content)
                    }
                }
                Key{
                    width: itemWidth
                    height: itemHeight
                    content: "Cap"
                    onClick: {
                        lowCase = !lowCase
                        switchCase(numCase, lowCase)
                    }
                }
            }

            Row{
                id:row3
                width: parent.width
                height: itemHeight
                spacing: 3
                Key{
                    id:num
                    width: 100
                    height: itemHeight
                    content: "123"
                    onClick: {
                        numCase = !numCase
                        switchCase(numCase, lowCase)
                    }
                }
                Key{
                    width: row3.width - num.width - hide.width - row3.spacing * 2
                    height: itemHeight
                    content: " "
                    onClick: key(content)
                }
                Key{
                    id:hide
                    width: 100
                    height: itemHeight
                    content: "Hide"
                    onClick: root.visible = false
                }
            }

        }
    }

    function switchCase(toNum, toLowCase)
    {
        if(toNum)
        {
            rp0.model = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]
            rp1.model = ["@", "#", "%", "&", "*", "-", "+", "(", ")"]
            rp2.model = ["!", "\"", "<", ">", "'", ":", ";", "/", "?"]
        }
        else
        {
            rp0.model = toLowCase ? ["q", "w", "e", "r", "t", "y", "u", "i", "o", "p"] : ["Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P"]
            rp1.model = toLowCase ? ["a", "s", "d", "f", "g", "h", "j", "k", "l"] : ["A", "S", "D", "F", "G", "H", "J", "K", "L"]
            rp2.model = toLowCase ? ["z", "x", "c", "v", "b", "n", "m", ",", "."] : ["Z", "X", "C", "V", "B", "N", "M", ",", "."]
        }
    }
}
