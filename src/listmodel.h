#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

#include "task.h"

class ListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum TaskRoles {
        DescriptionRole = Qt::UserRole + 1, // Роль для отображения текста
        CompletedRole                      // Пользовательская роль
    };

    explicit ListModel(QObject *parent = nullptr)
        : QAbstractListModel(parent)
    {}

    void addTask(const QString &description) {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        Task *task = new Task();
        task->setDescription(description);
        m_tasks.append(task);
        endInsertRows();
    }

    void removeTask(int index) {
        if (index >= 0 && index < m_tasks.size()) {
            beginRemoveRows(QModelIndex(), index, index);
            delete m_tasks. takeAt(index);
            endRemoveRows();
        }
    }

    void toggleTask(int index) {
        if (index >= 0 && index < m_tasks.size()) {
            Task *task = m_tasks.takeAt(index);
            task->setCompleted(!task->completed());
        }
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        if (parent.isValid())
            return 0;
        return m_tasks.size();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
    {
        if (!index.isValid() || index.row() >= m_tasks.size())
            return QVariant();

        Task *task = m_tasks.at(index.row());

        if (role == DescriptionRole) {
            return task->description();
        }
        if (role == CompletedRole) {
            return task->completed();
        }

        return QVariant();
    }

    QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles;
        roles[DescriptionRole] = "description"; // Имя роли для DisplayRole
        roles[CompletedRole] = "completed";   // Имя роли для CustomRole
        return roles;
    }

private:
    QList<Task*> m_tasks;  // Дополнительные данные (числа)
};


#endif //LISTMODEL_H
