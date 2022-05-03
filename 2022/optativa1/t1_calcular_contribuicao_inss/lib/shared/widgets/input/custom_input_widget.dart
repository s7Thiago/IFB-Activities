import 'package:flutter/material.dart';
import '../../styles/texts.dart';
import 'package:supercharged/supercharged.dart';

class CustomInputWidget extends StatelessWidget {
  final String title;
  final String content;
  final Alignment alignment;
  final void Function(String)? onChanged;

  const CustomInputWidget({
    Key? key,
    this.title = '',
    required this.content,
    this.alignment = Alignment.centerLeft,
    this.onChanged,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      width: MediaQuery.of(context).size.width * .5,
      alignment: alignment,
      padding: const EdgeInsets.only(
        top: 10,
        left: 10,
        right: 20,
      ),
      height: MediaQuery.of(context).size.height * .1,
      child: Row(
        children: [
          Text(title).inputBoxTitleStyle(),
          const SizedBox(width: 25),
          Expanded(
            child: TextField(
              style: const Text('').inputBoxContentStyle().style,
              keyboardType: TextInputType.number,
              cursorColor: "c45cf5".toColor(),
              decoration: const InputDecoration(
                border: InputBorder.none,
              ),
              onChanged: onChanged,
            ),
          ),
        ],
      ),
      decoration: BoxDecoration(
        color: "7448a7".toColor(),
        border: Border.fromBorderSide(
          BorderSide(
            width: 2,
            color: "c45cf5".toColor(),
          ),
        ),
      ),
    );
  }
}
