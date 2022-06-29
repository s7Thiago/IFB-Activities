class GastoMensal {
  int? _id;
  final int _ano;
  final String _mes;
  final String _finalidade;
  final double _valor;
  final String _tipoGasto;
  GastoMensal(this._id, this._ano, this._mes, this._finalidade, this._valor,
      this._tipoGasto);
  double get valor => _valor;
  String get finalidade => _finalidade;
  String get mes => _mes;
  int get ano => _ano;
  int get id => _id!;
  set id(int value) {
    _id = value;
  }

  get tipoGasto => _tipoGasto;
  Map<String, dynamic> getGastoMensal() {
    Map<String, dynamic> gastoMensal = {};
    gastoMensal["_id"] = _id;
    gastoMensal["ano"] = _ano;
    gastoMensal["mes"] = _mes;
    gastoMensal["finalidade"] = _finalidade;
    gastoMensal["valor"] = _valor;
    gastoMensal["tipo_gasto"] = _tipoGasto;
    return gastoMensal;
  }

  @override
  String toString() {
    return "Ano: $_ano \n Mês: $_mes \n Finalidade: $_finalidade\nValor: $_valor \n Tipo de Gasto: $_tipoGasto";
  }
}
