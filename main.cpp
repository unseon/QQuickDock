#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "qdockablewindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<QDockableWindow>("QtQuick.Window.Dock", 1, 0, "DockableWindow");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));



    return app.exec();
}
