import 'package:flutter/foundation.dart';

class CalcProvider extends ChangeNotifier {
  double _salario = 0;
  double _totalInss = 0;
  double _percentualInss = 0;
  double _totalIrpf = 0;
  double _percentualIrpf = 0;

  double get salario => _salario;
  double get totalInss => _totalInss;
  double get percentualInss => _percentualInss;
  double get totalIrpf => _totalIrpf;
  double get percentualIrpf => _percentualIrpf;

  set salario(double value) {
    _salario = value;
    notifyListeners();
  }

  set totalInss(double value) {
    _totalInss = value;
    notifyListeners();
  }

  set percentualInss(double value) {
    _percentualInss = value;
    notifyListeners();
  }

  set totalIrpf(double value) {
    _totalIrpf = value;
    notifyListeners();
  }

  set percentualIrpf(double value) {
    _percentualIrpf = value;
    notifyListeners();
  }
}
