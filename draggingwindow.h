#ifndef DRAGGINGWINDOW_H
#define DRAGGINGWINDOW_H

#include <QQuickWindow>

class DraggingWindow : public QQuickWindow
{
    Q_OBJECT
public:
    explicit DraggingWindow(QWindow* parent = 0);


protected:
    void mouseMoveEvent(QMouseEvent *ev);

};

#endif // DRAGGINGWINDOW_H
