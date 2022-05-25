class Task {
   String taskName;
  bool isCompleted;

  Task({required this.taskName, this.isCompleted = false});

  fromJson(Map<String, dynamic> json) {
    taskName = json['atividade'];
    isCompleted = json['concluida'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = {};
    data['atividade'] = taskName;
    data['concluida'] = isCompleted;
    return data;
  }
}
