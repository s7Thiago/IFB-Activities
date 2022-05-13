import 'package:flutter/material.dart';

class CustomInput extends StatelessWidget {
  final TextEditingController controller;

  const CustomInput({
    Key? key,
    required this.controller,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.all(16),
      padding: const EdgeInsets.only(left: 16, bottom: 2),
      alignment: Alignment.center,
      height: 50,
      width: MediaQuery.of(context).size.width * .5,
      child: TextField(
        controller: controller,
        cursorColor: Colors.white,
        maxLength: 8,
        maxLines: 1,
        cursorHeight: 25,
        style: const TextStyle(color: Colors.white),
        decoration: const InputDecoration(border: InputBorder.none),
      ),
      decoration: const BoxDecoration(
          color: Colors.blueGrey,
          borderRadius: BorderRadius.all(Radius.circular(100))),
    );
  }
}