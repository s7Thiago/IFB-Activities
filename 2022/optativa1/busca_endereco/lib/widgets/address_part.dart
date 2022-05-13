import 'package:flutter/material.dart';

class AddressPart extends StatelessWidget {
  final String title;
  final String content;

  const AddressPart({
    Key? key,
    required this.title,
    required this.content,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ListTile(
      title: Text(title),
      subtitle: Text(content),
    );
  }
}