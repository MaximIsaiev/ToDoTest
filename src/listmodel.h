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
        DescriptionRole = Qt::UserRole + 1,
        CompletedRole
    };

    explicit ListModel(QObject *parent = nullptr);
    void addTask(const QSharedPointer<Task>& task);
    void removeTask(int index);
    void toggleTask(int index);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = DescriptionRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<QSharedPointer<Task>> m_tasks;
};


#endif //LISTMODEL_H
