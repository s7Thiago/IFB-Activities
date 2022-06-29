// ignore_for_file: avoid_print

import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:t2_persistencia_interna/model/task.dart';
import 'package:t2_persistencia_interna/pages/home/home_controller.dart';
import 'package:t2_persistencia_interna/widgets/dismissible_item.dart';

class Home extends StatefulWidget {
  const Home({Key? key}) : super(key: key);

  @override
  createState() => _HomeState();
}

class _HomeState extends State<Home> {
  final controller = HomeController();

  @override
  void initState() {
    super.initState();

    controller.service.readTasks().then((String res) {
      print('Tarefas: $res');
      setState(() {
        controller.tasks = json.decode(res);
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Task List'), centerTitle: true),
      body: RefreshIndicator(
        onRefresh: controller.sortTasks,
        child: ListView.builder(
            itemCount: controller.tasks.length,
            itemBuilder: (ctx, index) {
              Task task = Task.fromMap(controller.tasks[index]);
              return DismissibleItem(
                task: task,
                homeController: controller,
                index: index,
              );
            }),
      ),
      bottomNavigationBar: Container(
        height: 80,
        width: 500,
        padding: const EdgeInsets.symmetric(horizontal: 20),
        child: Row(
          children: [
            Expanded(
              child: TextField(
                maxLines: 1,
                controller: controller.textController,
                decoration: const InputDecoration(labelText: 'New Task'),
              ),
            ),
            const SizedBox(width: 20),
            FloatingActionButton(
              onPressed: () => setState(controller.addNewTask),
              // style: ButtonStyle(
              //   minimumSize: MaterialStateProperty.all(const Size(50, 50)),
              // ),
              child: const Icon(Icons.add),
            ),
          ],
        ),
      ),
    );
  }
}
