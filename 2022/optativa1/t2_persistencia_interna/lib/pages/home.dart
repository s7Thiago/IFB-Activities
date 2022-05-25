import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:t2_persistencia_interna/model/task.dart';
import 'package:t2_persistencia_interna/repository/impl/TasksRepositoryImpl.dart';
import 'package:t2_persistencia_interna/service/impl/task-service_impl.dart';
import 'package:t2_persistencia_interna/service/tasks_service.dart';

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  final _newTaskTextController = TextEditingController();
  TasksService service = TasksServiceImpl(repository: TasksRepositoryimpl());
  Map<String, dynamic>? _lastRemoved;
  List _tasks = [];

  @override
  void initState() {
    super.initState();

    service.readTasks().then((res) {
      print('Tarefas: $res');
      setState(() {
        _tasks = json.decode(res);
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Task List'), centerTitle: true),
      bottomNavigationBar: Container(
        height: 80,
        width: 500,
        padding: const EdgeInsets.symmetric(horizontal: 20),
        child: Row(
          children: [
            Expanded(
              child: TextField(
                maxLines: 1,
                controller: _newTaskTextController,
                decoration: const InputDecoration(labelText: 'New Task'),
              ),
            ),
            const SizedBox(width: 20),
            ElevatedButton(
              onPressed: () {
                setState(() {
                  Map<String, dynamic> newTask = {};

                  // A new task
                  Task task = Task(
                    taskName: _newTaskTextController.text,
                    isCompleted: false,
                  );

                  // Converting the new task to json for store on file
                  newTask = task.toJson();

                  // Cleaning up text field
                  _newTaskTextController.text = '';

                  _tasks.add(newTask);

                  service.saveTasks(_tasks);

                });
              },
              child: const Icon(Icons.add),
              style: ButtonStyle(
                minimumSize: MaterialStateProperty.all(const Size(100, 50)),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
