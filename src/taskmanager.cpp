#include "taskmanager.h"


TaskManager::TaskManager(QObject *parent) : QObject(parent), m_model(new ListModel(this)) {}

void TaskManager::addTask(const QString &description) {
    const auto task = QSharedPointer<Task>(new Task(description, false));
    m_model->addTask(task);
    emit tasksChanged();
}

void TaskManager::removeTask(const int index) const {
    m_model->removeTask(index);
}

void TaskManager::toggleTask(const int index) const {
    m_model->toggleTask(index);
}

ListModel * TaskManager::model() const {
    return m_model;
}


