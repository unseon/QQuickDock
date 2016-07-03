#include "draggingwindow.h"
#include <QDebug>

DraggingWindow::DraggingWindow(QWindow* parent)
    : QQuickWindow(parent)
{
    setFlags(Qt::SplashScreen);
    setWidth(100);
    setHeight(30);
}

void DraggingWindow::mouseMoveEvent(QMouseEvent *ev)
{
    static int counter = 0;

    counter ++;
    qDebug() << "mouse move event" << counter;
    QQuickWindow::mouseMoveEvent(ev);
}
