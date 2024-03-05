#pragma once

#include <QQmlApplicationEngine>
class QGuiApplication;

class App
{
public:
    App();

    void start();

    QQmlApplicationEngine *const engine();

private:
    QQmlApplicationEngine m_engine;
};
