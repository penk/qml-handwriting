#include "handwritingengine.h"
#include <QTextCodec>
#include <QDebug>

HandwritingEngine::HandwritingEngine(QObject *parent) :
    QObject(parent)
{
    m_recognizer = zinnia::Recognizer::create();
    m_character = zinnia::Character::create();
    m_character->clear();

    m_character->set_width(300);
    m_character->set_height(300);
}

bool HandwritingEngine::loadModel(const QString model)
{
    if (!m_recognizer->open(model.toLocal8Bit())) {
        qDebug("can't load model file");
        return false;
    }
    qDebug() << "model" << model  <<  " loaded";
    return true;
}

QStringList HandwritingEngine::query(int s, int x, int y)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    m_results.clear();
    m_character->add(s, x, y);

    m_result = m_recognizer->classify(*m_character, 8);
    if (!m_result)
        qDebug("can't find m_result");
    else
    {
        for (u_int32_t i = 0; i < m_result->size(); ++i)
        {
            qDebug() << "m_result found : " << QString::fromLocal8Bit(m_result->value(i));
            m_results << QString::fromLocal8Bit(m_result->value(i));
            emit resultsChanged(m_results);
        }
    }
    return m_results;
}

void HandwritingEngine::clear()
{
    m_character->clear();
}

QStringList HandwritingEngine::results() const
{
    return m_results;
}
