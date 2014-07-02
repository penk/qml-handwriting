#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlContext>

#include "handwritingengine.h"


int main(int argc, char *argv[]) {

    QGuiApplication app(argc, argv);
    QQuickView view;
    HandwritingEngine data;

    data.loadModel(QStringLiteral("/usr/share/tegaki/models/zinnia/handwriting-zh_TW.model"));

    view.rootContext()->setContextProperty("Zinnia", &data);
    view.setSource(QUrl::fromLocalFile("main.qml"));
    view.show();

    return app.exec();
}
