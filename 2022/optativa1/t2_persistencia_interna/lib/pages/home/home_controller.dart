import 'package:flutter/cupertino.dart';
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

  void addNewTask() {}
}
