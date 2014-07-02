import QtQuick 2.2

Item {
    id:root
    width:768
    height:263
    anchors.margins: 4

    Image { source: "asset/bg.png"; anchors.fill: parent; }

    Writing {
        id:canvas
        width: 369;
        height: 263;
        x: 200
        y: 0
    }

    Flow {
        anchors.top: root.top;
        anchors.left: canvas.right
        anchors.right: root.right

        Repeater {
            model: Zinnia.results
            delegate: Item {
                id: delegateItem
                width: 99
                height: text.height
                Rectangle{
                    id: delegateBackground
                    anchors.fill: parent;
                    color: "transparent"
                    opacity: .5
                }
                Text {
                    id: text
                    width: parent.width
                    font.pointSize: 42
                    text: modelData
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    anchors.fill: parent
                    onPressed: delegateBackground.color = "black"
                    onReleased: delegateBackground.color = "transparent"
                    onClicked: console.log(modelData)
                }
            }
        }
    }

    Item {
        id:clearbutton
        width:100
        height:65

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 100

        MouseArea {
            anchors.fill:parent
            onClicked: canvas.clear();
        }
    }
}
