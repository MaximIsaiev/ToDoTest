import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import todoList 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: "To-Do List"

    ListModel {
        id: taskManager
    }

    Column {
        width: parent.width
        spacing: 10
        padding: 20

        TextInput {
            id: taskInput
            width: parent.wigth
            text: "Введите задачу"
        }

        Button {
            id: button
            text: "Добавить"
            onClicked: {
                if (taskInput.text !== "") {
                    taskManager.addTask(taskInput.text)
                    taskInput.text = "Введите задачу"
                    console.log("task")
                    console.log(taskManager.tasks)
                } else {
                    console.log("Enter task")
                }
            }

            contentItem: Text {
                text: button.text
                color: "#ffffff"
                font.bold: true
            }

            background: Rectangle {
                color: "#005291"
            }
        }

        ListView {
            width: parent.width
            height: 450
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
            header: Text {
                text: "Список задач"
                font.pixelSize: 15
            }

            model: ListModel {
                id: tasksModel
                Component.onCompleted: {
                    for (let i = 0; i < taskManager.tasks.length; i++)
                        tasksModel.append( {completed: taskManager.tasks[i].completed,
                                                    description: taskManager.tasks[i].description,
                                                    index: i});
                }
            }

            delegate: Item {
                width: parent.width
                height: 40

                Row {
                    spacing: 10
                    anchors.verticalCenter: parent.verticalCenter

                    CheckBox {
                        checked: model.completed
                        onClicked: taskManager.toggleTask(model.index)
                    }

                    Text {
                        text: model.description
                    }

                    Button {
                        text: "Удалить"
                        onClicked: taskManager.removeTask(model.index)
                    }
                }
            }

            onModelChanged: {
                tasksModel.clear();
                for (let i = 0; i < taskManager.tasks.length; i++)
                    tasksModel.append({completed: taskManager.tasks[i].completed,
                                            description: taskManager.tasks[i].description,
                                            index: i});
            }
        }
    }
}