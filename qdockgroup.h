#ifndef QDOCKGROUP_H
#define QDOCKGROUP_H

#include <QObject>
#include <QList>

#include "qdockablewindow.h"

class QDockGroup : public QObject
{
    Q_OBJECT
public:
    explicit QDockGroup(QObject *parent = 0);

    void addDockWindow(QDockableWindow* window);
    void dockWindowMoved(QDockableWindow* window, int x, int y);
signals:

public slots:

private:
    QList<QDockableWindow*> windowList;
};

#endif // QDOCKGROUP_H
