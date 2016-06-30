#ifndef QDOCKABLEWINDOW_H
#define QDOCKABLEWINDOW_H

#include <QWindow>

class QDockGroup;

class QDockableWindow : public QWindow
{
public:
    QDockableWindow();

    int id;
    QDockGroup* dockGroup;

    void setDockGroup(QDockGroup* group);


protected:
    void moveEvent(QMoveEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
    void focusInEvent(QFocusEvent *ev);

public slots:
    void onXChanged(int arg);
};

#endif // QDOCKABLEWINDOW_H
