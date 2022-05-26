import 'package:t2_persistencia_interna/repository/impl/TasksRepositoryImpl.dart';
import 'package:t2_persistencia_interna/service/impl/task-service_impl.dart';

class HomeController{
  List _tasks = [];

  get service => TasksServiceImpl(repository: TasksRepositoryimpl());
  List get tasks => _tasks;

  // set tasks
  set tasks(List tasks) => _tasks = tasks;
}