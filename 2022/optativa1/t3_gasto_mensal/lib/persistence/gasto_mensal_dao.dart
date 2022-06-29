import 'dart:io';
import 'package:path_provider/path_provider.dart';
import 'package:sqflite/sqflite.dart';
import 'package:path/path.dart';
import 'package:t3_gasto_mensal/model/gasto_mensal.dart';

class GastoMensalDao {
//Definição dos campos da tabela
  static const _databaseName = "gasto.db";
  static const _databaseVersion = 1;
  static const table = "gastomensal";
  static const _id = "_id";
  static const _ano = "ano";
  static const _mes = "mes";
  static const _finalidade = "finalidade";
  static const _valor = "valor";
  static const _tipoGasto = "tipo_gasto";
// torna esta classe singleton
  GastoMensalDao._privateConstructor();
  static final GastoMensalDao instance = GastoMensalDao._privateConstructor();

  static Database? _database;
// tem somente uma referência ao banco de dadosstatic Database? _database;
  Future<Database> get database async {
    if (_database != null) return _database!;
// instancia o db na primeira vez que for acessado
    _database = await _initDatabase();
    return _database!;
  }

// abre o banco de dados ou cria, se ele não existir
  _initDatabase() async {
    Directory documentsDirectory = await getApplicationDocumentsDirectory();
    String path = join(documentsDirectory.path, _databaseName);
    return await openDatabase(path,
        version: _databaseVersion, onCreate: _onCreate);
  }

// Código SQL para criar o banco de dados e a tabela
  Future _onCreate(Database db, int version) async {
    await db.execute("""
CREATE TABLE $table (
$_id INTEGER PRIMARY KEY,
$_ano INTEGER NOT NULL,
$_mes TEXT NOT NULL,
$_finalidade TEXT NOT NULL,
$_valor REAL NOT NULL,
$_tipoGasto TEXT NOT NULL
)
""");
  }

  static Future<int> inserir(GastoMensal gastoMensal) async {
    var result = 0;
    try {
      Database db = await instance.database;
      result = await db.insert(table, Map.from(gastoMensal.getGastoMensal()));
    } on Exception {
      return 0;
    }
    return result;
  }

  static Future<List<GastoMensal>> findAll() async {
    List<Map<String, Object?>> result;
    List<GastoMensal> gastos;
    try {
      final Database db = await instance.database;
      result = await db.query(table);
      gastos = _toList(result);
    } on Exception {
      return [];
    }
    return gastos;
  }

  static List<GastoMensal> _toList(List<Map<String, dynamic>> result) {
    final List<GastoMensal> gastos = [];
    for (Map<String, dynamic> row in result) {
      final GastoMensal gastoMensal = GastoMensal(row[_id], row[_ano],
          row[_mes], row[_finalidade], row[_valor], row[_tipoGasto]);
      gastos.add(gastoMensal);
    }
    return gastos;
  }

  static Future<int> alterar(GastoMensal gastoMensal) async {
    var result = 0;
    try {
      Database db = await instance.database;
      result = await db.update(table, gastoMensal.getGastoMensal(),
          where: "$_id = ?", whereArgs: [gastoMensal.id]);
    } on Exception {
      return 0;
    }
    return result;
  }

  static Future<int> excluir(int id) async {
    var result = 0;
    try {
      Database db = await instance.database;
      result = await db.delete(table, where: "$_id = ?", whereArgs: [id]);
    } on Exception {
      return 0;
    }
    return result;
  }
}
