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

    // required to work (handwritingEngine)
    property QtObject engine

    property int strokes: 0

    MouseArea {
        id:mousearea
        hoverEnabled:true
        anchors.fill: parent
        onClicked: drawPoint();

        onPositionChanged:  {
            requestPaint()
        }

        onPressed: {
            paintX = mouseX;
            paintY = mouseY;
        }

        onReleased: {
            var array = Straw.shortStraw(Script.getList());
            var ctx = getContext("2d")

            ctx.beginPath();
            ctx.strokeStyle = 'red';
            ctx.moveTo(array[0].x, array[0].y);
            ctx.lineWidth = 2;
            for (var i = 0; i < array.length; i++) {
                //                console.log("strokes "+strokes+": " + array[i].x + ", "+ array[i].y );
                engine.query(strokes, array[i].x, array[i].y);
                if (i > 0)
                    ctx.lineTo(array[i].x, array[i].y);
            }

            ctx.stroke();
            ctx.closePath();

            Script.clear();
            strokes++;
        }
    }

    onPaint: {
        // draw segments
        if (mousearea.pressed) {
            var ctx = getContext("2d")
            ctx.strokeStyle = drawColor
            ctx.lineWidth = lineWidth
            ctx.beginPath()
            ctx.moveTo(paintX, paintY)
            paintX = mousearea.mouseX;
            paintY = mousearea.mouseY;
            ctx.lineTo(mousearea.mouseX, mousearea.mouseY)
            ctx.stroke()
            ctx.closePath()
            Script.addItem(paintX, paintY)
        }
    }

    function drawPoint() {
        var ctx = canvas.getContext("2d")

        ctx.lineWidth = lineWidth
        ctx.fillStyle = drawColor
        ctx.fillRect(mousearea.mouseX, mousearea.mouseY, 2, 2);
    }

    // reset everything
    function clear() {
        var ctx = canvas.getContext("2d")

        strokes = 0;
        engine.clear();
        ctx.clearRect(0, 0, width, height);
    }
}
