#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <qobject.h>
#include "listmodel.h"
#include "task.h"

class TaskManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(ListModel *model READ model CONSTANT)
    QML_ELEMENT
public:
    explicit TaskManager(QObject *parent = nullptr);
    Q_INVOKABLE void addTask(const QString &description);
    Q_INVOKABLE void removeTask(int index) const;
    Q_INVOKABLE void toggleTask(int index) const;
    ListModel* model() const;

private:
    ListModel *m_model;

signals:
    void tasksChanged();
};



#endif //TASKMANAGER_H
