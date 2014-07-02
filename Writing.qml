import QtQuick 2.2

import "js/shortstraw.js" as Straw
import "js/script.js" as Script

Canvas {
    id:canvas

    property int paintX
    property int paintY
    property int count: 0
    property int lineWidth: 5
    property string drawColor: "black"
//    property variant ctx: getContext("2d")

    property int strokes: 0

    MouseArea {
        id:mousearea
        hoverEnabled:true
        anchors.fill: parent
        onClicked: drawPoint();
        onPositionChanged:  {
            paintX = mouseX;
            paintY = mouseY;
            requestPaint()
        }

        onReleased: {
            var array = Straw.shortStraw(Script.getList());
            var ctx = canvas.getContext("2d")

            ctx.beginPath();
            ctx.strokeStyle = 'red';
            ctx.moveTo(array[0].x, array[0].y);
            ctx.lineWidth = 2;
            for (var i = 0; i < array.length; i++) {
                console.log("strokes "+strokes+": " + array[i].x + ", "+ array[i].y );
                Zinnia.query(strokes, array[i].x, array[i].y);
                if (i>0) ctx.lineTo(array[i].x, array[i].y);
            }

            ctx.stroke();
            ctx.closePath();

            Script.clear();
            strokes++;
        }
    }

    onPaint: {
        if (mousearea.pressed) {
            var ctx = getContext("2d")
            ctx.beginPath();
            ctx.strokeStyle = drawColor
            ctx.lineWidth = lineWidth
            ctx.moveTo(paintX, paintY);
            ctx.lineTo(mousearea.mouseX, mousearea.mouseY);
            ctx.stroke();
            ctx.closePath();
            Script.addItem(paintX, paintY);
        }
    }

    function drawLineSegment() {
    }

    function drawPoint() {
        var ctx = canvas.getContext("2d")

        ctx.lineWidth = lineWidth
        ctx.fillStyle = drawColor
        ctx.fillRect(mousearea.mouseX, mousearea.mouseY, 2, 2);
    }

    function clear() {
        var ctx = canvas.getContext("2d")

        strokes=0;
        Zinnia.clear();
        ctx.clearRect(0, 0, width, height);
    }
}
