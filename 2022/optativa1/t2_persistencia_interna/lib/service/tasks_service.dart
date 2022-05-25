import 'dart:io';

abstract class TasksService{

  Future<File> createTasksFile();
  Future<File> saveTasks(List tasks);
  Future<String> readTasks();

}