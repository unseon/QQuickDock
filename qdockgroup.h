#ifndef QDOCKGROUP_H
#define QDOCKGROUP_H

#include <QObject>
#include <QList>

#include "qdockablewindow.h"
#include "draggingwindow.h"

class QDockGroup : public QObject
{
    Q_OBJECT
private:
    explicit QDockGroup(QObject *parent = 0);

public:
    static QDockGroup* instance();
    static DraggingWindow* draggingWindow();

signals:

public slots:



};

#endif // QDOCKGROUP_H
