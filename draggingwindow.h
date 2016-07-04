#ifndef DRAGGINGWINDOW_H
#define DRAGGINGWINDOW_H

#include <QQuickWindow>

class DraggingWindow : public QQuickWindow
{
    Q_OBJECT
public:
    explicit DraggingWindow(QWindow* parent = 0);


protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);


private:
    QPoint mOrigin;
    bool mPressing;
};

#endif // DRAGGINGWINDOW_H
