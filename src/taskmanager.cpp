//
// Created by daria on 29.01.2025.
//

#include "taskmanager.h"

TaskManager::TaskManager(QObject *parent) : QObject(parent) {}

void TaskManager::addTask(const QString &description) {
    Task *task = new Task(description, false);
    m_tasks.append(task);
    emit tasksChanged();
}

void TaskManager::removeTask(int index) {
    if (index > 0 && index <= m_tasks.size()) {
        delete m_tasks.takeAt(index);
        emit tasksChanged();
    }

}

void TaskManager::toggleTask(int index) {
    if (index > 0 && index <= m_tasks.size()) {
        Task *task = m_tasks.takeAt(index);
        if (task)
            task->setCompleted(!task->completed());
    }
}

QList<Task*> TaskManager::tasks() {
    return m_tasks;
}
