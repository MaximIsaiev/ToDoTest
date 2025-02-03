#include "task.h"

Task::Task(){}

Task::Task(const QString &description, bool completed) :
    m_description(description),
    m_completed(completed)
{}

void Task::setDescription(const QString &description) {
    m_description = description;
}

void Task::setCompleted(bool completed) {
    m_completed = completed;
}

bool Task::completed() const {
    return m_completed;
}

QString Task::description() const {
    return m_description;
}
