import "Canvas"
import Qt 4.7

Item {
    id:root
    width:768
    height:263

    Image { source: "asset/bg.png"; anchors.fill: parent; }
    anchors.margins: 4

    Writing {
        id:canvas
        width: 369;
        height: 263;
        x: 200
        y: 0
    }

    Text { id: text; 
        width: 140;
        font.family: "Helvetica"
        font.pointSize: 42
        wrapMode: Text.Wrap;
        anchors.top: parent.top;
        anchors.right: parent.right;
        anchors.rightMargin: 20;
        anchors.topMargin: -10;
        text: "" 
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
