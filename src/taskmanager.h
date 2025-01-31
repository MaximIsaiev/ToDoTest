#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <qobject.h>
#include "task.h"

class TaskManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<Task*> tasks READ tasks)
    QML_ELEMENT
public:
    explicit TaskManager(QObject *parent = nullptr);
    Q_INVOKABLE void addTask(const QString &description);
    Q_INVOKABLE void removeTask(int index);
    Q_INVOKABLE void toggleTask(int index);
    Q_INVOKABLE QList<Task*> tasks();

private:
    QList<Task*> m_tasks;

signals:
    void tasksChanged();
};



#endif //TASKMANAGER_H
