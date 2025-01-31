#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/listmodel.h"
#include "src/taskmanager.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    qmlRegisterType<Task>("todoList", 1, 0, "Task");
    qmlRegisterType<TaskManager>("todoList", 1, 0, "TaskManager");
    qmlRegisterType<ListModel>("todoList", 1, 0, "ListModel");
    QQmlApplicationEngine engine;
    // TaskManager taskManager;
    // engine.rootContext()->setContextProperty("taskManager", &taskManager);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);
    return app.exec();
}
