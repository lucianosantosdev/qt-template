#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "applib/src/App.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    App a;
    a.start();
    return app.exec();
}
