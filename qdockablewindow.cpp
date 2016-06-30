#include "qdockablewindow.h"

#include <QDebug>

QDockableWindow::QDockableWindow()
{
    connect(this, &QDockableWindow::xChanged, this, &QDockableWindow::onXChanged);
}

void QDockableWindow::setDockGroup(QDockGroup *group)
{
    dockGroup = group;
}

void QDockableWindow::moveEvent(QMoveEvent *ev)
{
    QWindow::moveEvent(ev);

    qDebug() << "moveEvent";
}

bool QDockableWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    QWindow::nativeEvent(eventType, message, result);

    qDebug() << eventType;
}

void QDockableWindow::focusInEvent(QFocusEvent *ev)
{
    QWindow::focusInEvent(ev);

    qDebug() << "window" << id << "focused";
}

void QDockableWindow::onXChanged(int arg)
{
    qDebug() << "onXChanged" << arg;
}

void QDockableWindow::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug() << "window " << id << " mouse move event";
}
