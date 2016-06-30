#include "qdockgroup.h"

QDockGroup::QDockGroup(QObject *parent) : QObject(parent)
{

}

void QDockGroup::addDockWindow(QDockableWindow* window)
{
    windowList.append(window);
}

void QDockGroup::dockWindowMoved(QDockableWindow* window, int x, int y)
{

}
