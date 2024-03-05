#include "App.h"
#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

App::App()
{
    QObject::connect(
        &m_engine,
        &QQmlApplicationEngine::objectCreationFailed,
        QCoreApplication::instance(),
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
}

void App::start()
{
    const QUrl url(u"qrc:/app/ui/Main.qml"_qs);
    m_engine.load(url);
}

QQmlApplicationEngine *const App::engine()
{
    return &m_engine;
}
