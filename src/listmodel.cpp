//
// Created by daria on 31.01.2025.
//

#include "listmodel.h"

ListModel::ListModel(QObject *parent) : QAbstractListModel(parent) {}

int ListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_tasks.size();
}

void ListModel::addTask(const QSharedPointer<Task>& task)
{
    beginInsertRows(QModelIndex(), ListModel::rowCount(), ListModel::rowCount());
    m_tasks.append(task);
    endInsertRows();
}

void ListModel::removeTask(const int index)
{
    if (index >= 0 && index < m_tasks.size()) {
        beginRemoveRows(QModelIndex(), index, index);
        m_tasks.removeAt(index);
        endRemoveRows();
    }
}

void ListModel::toggleTask(const int index)
{
    if (index >= 0 && index < m_tasks.size()) {
        QSharedPointer<Task> task = m_tasks.takeAt(index);
        task->setCompleted(!task->completed());
    }
}

QVariant ListModel::data(const QModelIndex &index, const int role) const
{
    if (!index.isValid() || index.row() >= m_tasks.size())
        return QVariant();

    const auto task = m_tasks.at(index.row());

    if (role == DescriptionRole) {
        return task->description();
    }
    if (role == CompletedRole) {
        return task->completed();
    }

    return QVariant();
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[DescriptionRole] = "description";
    roles[CompletedRole] = "completed";
    return roles;
}

