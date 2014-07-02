#ifndef HandwritingEngine_H
#define HandwritingEngine_H

#include <QObject>
#include <QStringList>
#include <zinnia.h>

class HandwritingEngine : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList results READ results NOTIFY resultsChanged)
public:
    explicit HandwritingEngine(QObject *parent = 0);

    bool    loadModel(const QString model);
    Q_INVOKABLE QStringList query(int s, int x, int y);
    Q_INVOKABLE void        clear();

    QStringList results() const;
signals:
    QStringList resultsChanged(QStringList);

public slots:

private:
    zinnia::Recognizer* m_recognizer;
    zinnia::Character*  m_character;
    zinnia::Result*     m_result;
    QStringList         m_results;
};

#endif // HandwritingEngine_H
