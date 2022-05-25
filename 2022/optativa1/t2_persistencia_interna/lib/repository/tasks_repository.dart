import 'dart:io';

abstract class TasksRepository{

  Future<File> createTasksFile();
  Future<File> saveTasks(List tasks);
  Future<String> readTasks();

}