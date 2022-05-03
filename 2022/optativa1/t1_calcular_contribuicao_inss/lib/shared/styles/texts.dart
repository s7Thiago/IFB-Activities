import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:supercharged/supercharged.dart';

extension MyTextStyles on Text {
  Text titleStyle() {
    return Text(
      data!,
      style: GoogleFonts.inter(
        fontSize: 30,
        fontWeight: FontWeight.w500,
        color: "f1a3f5".toColor(),
      ),
    );
  }

  Text contentStyle() {
    return Text(
      data!,
      style: GoogleFonts.inter(
        fontSize: 45,
        fontWeight: FontWeight.w200,
        color: Colors.white60,
      ),
    );
  }

  Text inputBoxContentStyle() {
    return Text(
      data!,
      style: contentStyle().style!.copyWith(fontSize: 25),
    );
    ;
  }

  Text inputBoxTitleStyle() {
    return Text(
      data!,
      style: titleStyle().style!.copyWith(fontSize: 15),
    );
  }
}
