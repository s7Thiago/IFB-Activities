import 'dart:convert' show json;
import 'dart:io';

import 'package:path_provider/path_provider.dart';
import 'package:t2_persistencia_interna/repository/tasks_repository.dart';

class TasksRepositoryImpl implements TasksRepository {
  @override
  Future<File> createTasksFile() async {
    final dir = await getApplicationDocumentsDirectory();
    final File file = await File('${dir.path}/app_tasks.json').create();
    file.writeAsString(json.encode([]));
    return file;
  }

  @override
  Future<String> readTasks() async {
    try {

      final File file = await createTasksFile();
      return file.readAsString();

    } catch (e) {
      return Future.value("Error while reading file!");
    }
  }

  @override
  Future<File> saveTasks(List tasks) async {
    String data = json.encode(tasks);
    final File file = await createTasksFile();
    return file.writeAsString(data); 
  }
  

}