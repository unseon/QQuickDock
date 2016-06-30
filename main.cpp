#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "qdockablewindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    QDockableWindow* dockWindow01 = new QDockableWindow();
    dockWindow01->id = 1;
    dockWindow01->resize(400, 400);

    QDockableWindow* dockWindow02 = new QDockableWindow();
    dockWindow02->id = 2;
    dockWindow02->show();
    dockWindow02->resize(400, 400);
    dockWindow01->show();


    return app.exec();
}
