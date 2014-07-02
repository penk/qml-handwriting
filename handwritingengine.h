#ifndef HandwritingEngine_H
#define HandwritingEngine_H

#include <QObject>
#include <QStringList>
#include <zinnia.h>

class HandwritingEngine : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList results READ results NOTIFY resultsChanged)
    Q_PROPERTY(int drawing_height READ drawing_height WRITE setDrawing_height NOTIFY drawing_heightChanged)
    Q_PROPERTY(int drawing_width READ drawing_width WRITE setDrawing_width NOTIFY drawing_widthChanged)
public:
    explicit HandwritingEngine(QObject *parent = 0);

    bool    loadModel(const QString model);
    Q_INVOKABLE QStringList query(int s, int x, int y);
    Q_INVOKABLE void        clear();

    QStringList results() const;
    int         drawing_height() const;
    int         drawing_width() const;

signals:
    QStringList resultsChanged(QStringList);
    int         drawing_heightChanged(int);
    int         drawing_widthChanged(int);

public slots:
    void    setDrawing_height(const int height);
    void    setDrawing_width(const int width);

private:
    zinnia::Recognizer* m_recognizer;
    zinnia::Character*  m_character;
    zinnia::Result*     m_result;

    QStringList         m_results_list;
    int                 m_results_size;
    int                 m_drawing_height;
    int                 m_drawing_width;
    QString             m_model_path;
};

#endif // HandwritingEngine_H
