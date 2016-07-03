#include "qdockgroup.h"

QDockGroup::QDockGroup(QObject *parent) : QObject(parent)
{

}

QDockGroup* QDockGroup::instance()
{
    static QDockGroup* sInstance = new QDockGroup();

    return sInstance;
}

DraggingWindow* QDockGroup::draggingWindow()
{
    static DraggingWindow* sDraggingWindow = new DraggingWindow();

    return sDraggingWindow;
}
