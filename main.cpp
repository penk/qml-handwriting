#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlContext>

#include "handwritingengine.h"

//class ApplicationData : public QObject
//{
//    Q_OBJECT
//public:
//    Q_INVOKABLE QString query(int s, int x, int y) {

//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

//    str = QString("");
//    character->add(s, x, y);

//    result = recognizer->classify(*character, 8);
//    if (!result) qDebug("can't find resule");

//    for (size_t i = 0; i < result->size(); ++i)
//        str.append(result->value(i)).append(" ");

//    return str;
//    }

//    Q_INVOKABLE void clear() {
//        character->clear();
//    }

//    zinnia::Recognizer *recognizer;
//    zinnia::Character *character;
//    zinnia::Result *result;
//    QString str;

//};

int main(int argc, char *argv[]) {

    QGuiApplication app(argc, argv);
    QQuickView view;
    HandwritingEngine data;

//    data.recognizer = zinnia::Recognizer::create();
//    if (!data.recognizer->open("/usr/share/tegaki/models/zinnia/handwriting-zh_TW.model"))
//        qDebug("can't load model file");
//    else qDebug("model \"handwriting-zh_TW.model\" loaded");

//    data.character = zinnia::Character::create();
//    data.character->clear();

//    data.character->set_width(300);
//    data.character->set_height(300);

    view.rootContext()->setContextProperty("Zinnia", &data);
    view.setSource(QUrl::fromLocalFile("main.qml"));
    view.show();

    return app.exec();
}

//#include "handwriting.moc"
