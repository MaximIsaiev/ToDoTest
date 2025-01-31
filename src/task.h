#ifndef TASK_H
#define TASK_H
#include <qobject.h>
#include <qqml.h>
#include <qstring.h>

class Task : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(bool completed READ completed WRITE setCompleted)
    QML_ELEMENT
public:
    Task();
    Task(const QString &description, bool completed);
    void setDescription(const QString &description);
    void setCompleted(bool completed);
    bool completed() const;
    QString description() const;

// signals:
//     void descriptionChanged(const QString &description);
//     void completedChanged(const bool completed);

private:
    QString m_description;
    bool m_completed;
};

#endif //TASK_H
