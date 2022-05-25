import 'dart:io';

import 'package:t2_persistencia_interna/repository/tasks_repository.dart';
import 'package:t2_persistencia_interna/service/tasks_service.dart';

class TasksServiceImpl implements TasksService{

  final TasksRepository repository;

  TasksServiceImpl({required this.repository});

  @override
  Future<File> createTasksFile() => repository.createTasksFile();

  @override
  Future<String> readTasks() => repository.readTasks();

  @override
  Future<File> saveTasks(List tasks) => repository.saveTasks(tasks);

}