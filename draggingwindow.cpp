#include "draggingwindow.h"
#include <QDebug>

DraggingWindow::DraggingWindow(QWindow* parent)
    : QQuickWindow(parent),
      mPressing(false)
{
    setFlags(Qt::SplashScreen | Qt::WindowStaysOnTopHint);
    setWidth(100);
    setHeight(30);
    setMouseGrabEnabled(true);
}

void DraggingWindow::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << "mouse Press";
    mOrigin = ev->pos();
    mPressing = true;

    QQuickWindow::mousePressEvent(ev);
}

void DraggingWindow::mouseMoveEvent(QMouseEvent *ev)
{
    static int counter = 0;

    if (!mPressing) {
        return;
    }

    counter ++;
    qDebug() << "mouse move event" << counter;
    //QQuickWindow::mouseMoveEvent(ev);

    QPoint dockPosition = position();

    dockPosition += ev->pos() - mOrigin;

    setPosition(dockPosition);

    //ev->ignore();
}

void DraggingWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    mPressing = false;
}
