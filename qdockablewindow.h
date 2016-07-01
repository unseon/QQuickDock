#ifndef QDOCKABLEWINDOW_H
#define QDOCKABLEWINDOW_H

#include <QQuickWindow>

class QDockGroup;

class QDockableWindow : public QQuickWindow
{
    Q_OBJECT
public:
    explicit QDockableWindow(QWindow* parent = 0);

    int id;
    QDockGroup* dockGroup;

    void setDockGroup(QDockGroup* group);

signals:
    void focusIn();

protected:
    void moveEvent(QMoveEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
    void focusInEvent(QFocusEvent *ev);

public slots:
    void onXChanged(int arg);
    void test01();
};

#endif // QDOCKABLEWINDOW_H
