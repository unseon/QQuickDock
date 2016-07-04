#include "qdockablewindow.h"

#include <QDebug>
#include <QGuiApplication>

#include "qdockgroup.h"

QDockableWindow::QDockableWindow(QWindow* parent)
    : QQuickWindow(parent)
{
}

void QDockableWindow::setDockGroup(QDockGroup *group)
{
    dockGroup = group;
}

void QDockableWindow::moveEvent(QMoveEvent *ev)
{
    QQuickWindow::moveEvent(ev);

    //qDebug() << "moveEvent";
}

bool QDockableWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    bool rslt = QQuickWindow::nativeEvent(eventType, message, result);

    qDebug() << eventType;

    return rslt;
}

void QDockableWindow::focusInEvent(QFocusEvent *ev)
{
    QQuickWindow::focusInEvent(ev);

    //qDebug() << "window" << id << "focused";

    emit focusIn();
}

void QDockableWindow::mouseMoveEvent(QMouseEvent *ev)
{
    //qDebug() << "window " << id << " mouse move event";
    QQuickWindow::mouseMoveEvent(ev);
}

void QDockableWindow::test01()
{
    QWindowList list = QGuiApplication::topLevelWindows();

    qDebug() << "number of window = " << list.count();
}

void QDockableWindow::startDrag()
{
    qDebug() << "QDockableWindow::startDrag";

    DraggingWindow* dragWin = QDockGroup::draggingWindow();

    dragWin->show();
    dragWin->raise();

    dragWin->setPosition(position());
}

QDockableWindow* QDockableWindow::topLevelAt(const QPoint &pos)
{

    QWindowList list = QGuiApplication::topLevelWindows();
    for (int i = list.size()-1; i >= 0; --i) {
        QDockableWindow *w = qobject_cast<QDockableWindow*>(list[i]);

        qDebug() << w->geometry() << pos;

        if (w && w->isVisible() && w->geometry().contains(pos))
            return w;
    }

    return 0;
}
