import 'package:flutter/material.dart';
import 'package:supercharged/supercharged.dart';
import '../styles/texts.dart';

class InfoBoxWidget extends StatelessWidget {
  final String title;
  final String content;
  final Alignment alignment;

  const InfoBoxWidget({
    Key? key,
    this.title = '',
    required this.content,
    this.alignment = Alignment.centerLeft,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      width: MediaQuery.of(context).size.width * .5,
      alignment: alignment,
      padding: const EdgeInsets.only(
        top: 10,
        left: 20,
        right: 20,
      ),
      height: MediaQuery.of(context).size.height * .2,
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: alignment == Alignment.centerRight
            ? CrossAxisAlignment.end
            : CrossAxisAlignment.start,
        children: [
          Text(title).titleStyle(),
          const SizedBox(height: 20),
          Text(content).contentStyle(),
        ],
      ),
      decoration: BoxDecoration(
        color: "b148e9".toColor(),
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
