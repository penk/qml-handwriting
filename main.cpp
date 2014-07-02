#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlContext>

#include "handwritingengine.h"


int main(int argc, char *argv[]) {

    QGuiApplication app(argc, argv);
    QQuickView view;

    HandwritingEngine data;
    data.loadModel(QStringLiteral("/home/greys/Downloads/zinnia-tomoe-0.6.0-20080911/handwriting-zh_CN.model"));

    view.rootContext()->setContextProperty("Zinnia", &data);
    view.setSource(QUrl::fromLocalFile("main.qml"));
    view.show();

    return app.exec();
}
