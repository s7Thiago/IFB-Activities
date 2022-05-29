import 'dart:convert';

class Task {
  final String taskName;
  final bool isCompleted;
  Task({
    required this.taskName,
    required this.isCompleted,
  });

  Task copyWith({
    String? taskName,
    bool? isCompleted,
  }) {
    return Task(
      taskName: taskName ?? this.taskName,
      isCompleted: isCompleted ?? this.isCompleted,
    );
  }

  Map<String, dynamic> toMap() {
    return {
      'taskName': taskName,
      'isCompleted': isCompleted,
    };
  }

  factory Task.fromMap(Map<String, dynamic> map) {
    return Task(
      taskName: map['taskName'] ?? '',
      isCompleted: map['isCompleted'] ?? false,
    );
  }

  String toJson() => json.encode(toMap());

  factory Task.fromJson(String source) => Task.fromMap(json.decode(source));

  @override
  String toString() => 'Task(taskName: $taskName, isCompleted: $isCompleted)';

  @override
  bool operator ==(Object other) {
    if (identical(this, other)) return true;
  
    return other is Task &&
      other.taskName == taskName &&
      other.isCompleted == isCompleted;
  }

  @override
  int get hashCode => taskName.hashCode ^ isCompleted.hashCode;
}
