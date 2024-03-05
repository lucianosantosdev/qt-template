#include <App.h>
#include <gtest/gtest.h>

#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickWindow>
#include <QTest>
#include <QThread>
#include <QWindow>

void clickItem(QQuickItem *pItem, QWindow *pRootWindow)
{
    auto oPointF = pItem->mapToScene(QPoint(0, 0));
    auto oPoint = oPointF.toPoint();
    oPoint.rx() += pItem->width() / 2;
    oPoint.ry() += pItem->height() / 2;
    QTest::mouseClick(pRootWindow, Qt::LeftButton, Qt::NoModifier, oPoint);
}

TEST(myTestSuite, testCase)
{
    App a;
    a.start();

    auto *engine = a.engine();
    auto window = qobject_cast<QWindow *>(engine->rootObjects().first());
    auto *const button = engine->rootObjects().first()->findChild<QQuickItem *>("button");
    auto *const text = engine->rootObjects().first()->findChild<QQuickItem *>("text");
    int total = 1000;
    // When
    for (int var = 0; var < total; ++var) {
        clickItem(button, window);
        QCoreApplication::processEvents();
    }
    // Then
    ASSERT_EQ(QString::number(total), text->property("text").toString());
}
