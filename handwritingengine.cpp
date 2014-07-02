#include "handwritingengine.h"
#include <QTextCodec>

HandwritingEngine::HandwritingEngine(QObject *parent) :
    QObject(parent)
{
    recognizer = zinnia::Recognizer::create();
    if (!recognizer->open("/home/greys/Downloads/zinnia-tomoe-0.6.0-20080911/handwriting-zh_CN.model"))
        qDebug("can't load model file");
    else qDebug("model \"handwriting-zh_TW.model\" loaded");

    character = zinnia::Character::create();
    character->clear();

    character->set_width(300);
    character->set_height(300);
}

QString HandwritingEngine::query(int s, int x, int y)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    str.clear();
    character->add(s, x, y);

    result = recognizer->classify(*character, 8);
    if (!result)
        qDebug("can't find result");
    else
        for (int i = 0; i < result->size(); ++i)
            str.append(result->value(i)).append(" ");

    return str;
}

void HandwritingEngine::clear()
{
    character->clear();

}
