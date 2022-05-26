import 'package:flutter/cupertino.dart';
import 'package:t2_persistencia_interna/model/task.dart';
import 'package:t2_persistencia_interna/repository/impl/TasksRepositoryImpl.dart';
import 'package:t2_persistencia_interna/service/impl/task-service_impl.dart';

class HomeController extends ChangeNotifier {
  List _tasks = [];
  final _newTaskTextController = TextEditingController();

  get service => TasksServiceImpl(repository: TasksRepositoryimpl());
  List get tasks => _tasks;
  get textController => _newTaskTextController;

  // set tasks
  set tasks(List tasks) {
    _tasks = tasks;
    notifyListeners();
  }

  void addNewTask() {
    Map<String, dynamic> newTask = {};

                  // A new task
                  Task task = Task(
                    taskName: textController.text,
                    isCompleted: false,
                  );

                  // Converting the new task to json for store on file
                  newTask = task.toJson();

                  // Cleaning up text field content
                  textController.text = '';

                  // inserting new task on the list
                  tasks.add(newTask);

                  // Updating database file with new task
                  service.saveTasks(tasks);
  }
}
