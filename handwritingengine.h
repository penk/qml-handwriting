#ifndef HandwritingEngine_H
#define HandwritingEngine_H

#include <QObject>
#include <zinnia.h>

class HandwritingEngine : public QObject
{
    Q_OBJECT
public:
    explicit HandwritingEngine(QObject *parent = 0);
    Q_INVOKABLE QString     query(int s, int x, int y);
    Q_INVOKABLE void        clear();

signals:

public slots:

private:
    zinnia::Recognizer *recognizer;
    zinnia::Character *character;
    zinnia::Result *result;
    QString str;
};

#endif // HandwritingEngine_H
