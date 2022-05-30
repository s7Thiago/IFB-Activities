import 'package:flutter/material.dart';
import 'package:t2_persistencia_interna/model/task.dart';
import 'package:t2_persistencia_interna/pages/home/home_controller.dart';

class DismissibleItem extends StatefulWidget {
  final Task task;
  final int index;
  final HomeController homeController;

  const DismissibleItem({
    Key? key,
    required this.task,
    required this.homeController,
    required this.index,
  }) : super(key: key);

  @override
  State<DismissibleItem> createState() => _DismissibleItemState();
}

class _DismissibleItemState extends State<DismissibleItem> {
  @override
  Widget build(BuildContext context) {
    return Dismissible(
      key: Key(DateTime.now().millisecondsSinceEpoch.toString()),
      background: Container(
        color: Colors.red,
        child: const Align(
          alignment: Alignment(-0.9, 0.0),
          child: Icon(Icons.delete, color: Colors.white),
        ),
      ),
      direction: DismissDirection.startToEnd,
      child: CheckboxListTile(
        title: Text(widget.task.taskName),
        value: widget.task.isCompleted,
        secondary: CircleAvatar(
          child: widget.task.isCompleted
              ? const Icon(Icons.check)
              : const Icon(Icons.error),
        ),
        onChanged: (c) {
          setState(() {
            widget.task.isCompleted = c ?? true;
            widget.homeController.service.saveTasks(
              widget.homeController.tasks,
            );
          });
        },
      ),
      onDismissed: (direction) {
        setState(() {
          widget.homeController.lastRemoved = widget.task.toMap();
          widget.homeController.lastRemovedIndex = widget.index;
          widget.homeController.tasks
              .removeAt(widget.homeController.lastRemovedIndex!);

          // Updating task list
          widget.homeController.service.saveTasks(
            widget.homeController.tasks,
          );
          
          final snackBar = SnackBar(
            content: Text('Task \"${widget.task.taskName}\" was removed!'),
            action: SnackBarAction(
              label: "Undo",
              onPressed: () {
                setState(() {
                  widget.homeController.tasks.insert(
                    widget.homeController.lastRemovedIndex!,
                    widget.homeController.lastRemoved,
                  );

                  // Updating task list
                  widget.homeController.service.saveTasks(
                    widget.homeController.tasks,
                  );
                });
              },
            ),
            duration: const Duration(seconds: 2),
          );

          ScaffoldMessenger.of(context).removeCurrentSnackBar();
          ScaffoldMessenger.of(context).showSnackBar(snackBar);

        });
      },
    );
  }
}
