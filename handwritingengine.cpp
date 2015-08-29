#include "handwritingengine.h"
#include <QTextCodec>
#include <QDebug>

HandwritingEngine::HandwritingEngine(QObject *parent) :
    QObject(parent)
  , m_results_size(8)
  , m_drawing_height(263)
  , m_drawing_width(369)
  , m_model_path("/usr/share/tegaki/models/zinnia/handwriting-zh_TW.model")
  , m_loaded(false)
{
    m_recognizer = zinnia::Recognizer::create();
    loadModel(m_model_path);

    m_character = zinnia::Character::create();
    m_character->clear();

    m_character->set_height(m_drawing_height);
    m_character->set_width(m_drawing_width);
}

// Load the language model for text recognition
bool HandwritingEngine::loadModel(const QString model)
{
    if (!m_recognizer->open(model.toLocal8Bit())) {
        qDebug("can't load model file");
        m_loaded = false;
        return m_loaded;
    }
    qDebug() << "model" << model  <<  " loaded";
    m_loaded = true;
    return m_loaded;
}

// Process the drawn lines to produces results from the model
QStringList HandwritingEngine::query(int s, int x, int y)
{
    m_results_list.clear();
    emit resultsChanged(m_results_list);

    // add a line to the current character
    m_character->add(s, x, y);

    // based on current character being drawn, we get some result
    m_result = m_recognizer->classify(*m_character, m_results_size);
    if (!m_result)
        qDebug("can't find m_result");
    else
    {
        for (u_int32_t i = 0; i < m_result->size(); ++i)
        {
//            qDebug() << "m_result found : " << QString::fromLocal8Bit(m_result->value(i));
            m_results_list << QString::fromLocal8Bit(m_result->value(i));
            emit resultsChanged(m_results_list);
        }
    }
    return m_results_list;
}

void HandwritingEngine::clear()
{
    m_character->clear();
    m_results_list.clear();
    emit resultsChanged(m_results_list);
}

QStringList HandwritingEngine::results() const
{
    return m_results_list;
}

int HandwritingEngine::drawing_height() const
{
    return m_drawing_height;
}

int HandwritingEngine::drawing_width() const
{
    return m_drawing_width;
}

bool HandwritingEngine::loaded() const
{
    return m_loaded;
}

void HandwritingEngine::setDrawing_height(const int height)
{
    m_drawing_height = height;
    m_character->set_height(m_drawing_height);
    emit drawing_heightChanged(m_drawing_height);
}

void HandwritingEngine::setDrawing_width(const int width)
{
    m_drawing_width = width;
    m_character->set_width(m_drawing_width);
    emit drawing_widthChanged(m_drawing_width);
}
