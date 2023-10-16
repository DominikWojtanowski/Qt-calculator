#ifndef EMITTER_H
#define EMITTER_H

#include <QtWidgets>
#include <QtCore>
#include <QtGui>

class Emitter : public QObject
{
    Q_OBJECT
signals:
    void customSignal(int value);
};

#endif // EMITTER_H