#include "qdockablewindow.h"

#include <QDebug>
#include <QGuiApplication>

QDockableWindow::QDockableWindow(QWindow* parent)
    : QQuickWindow(parent)
{
    connect(this, &QDockableWindow::xChanged, this, &QDockableWindow::onXChanged);
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
    QQuickWindow::nativeEvent(eventType, message, result);

    qDebug() << eventType;
}

void QDockableWindow::focusInEvent(QFocusEvent *ev)
{
    QQuickWindow::focusInEvent(ev);

    //qDebug() << "window" << id << "focused";

    emit focusIn();
}

void QDockableWindow::onXChanged(int arg)
{
    //qDebug() << "onXChanged" << arg;
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
