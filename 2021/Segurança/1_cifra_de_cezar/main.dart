main() {
  String secret = 'Hoje temos dia de folga';
  String encoded = encodeMessage(secret, 4);
  String decoded = decodeMessage(encoded, 4);

  print('\n\nOriginal message: $secret');
  print('ENCODED: ${encoded}');
  print('Rollback encription: ${decoded}\n\n');
}

String decodeMessage(String message, int rotations) {
  rotations *= -1;

  var rotatedAlphabet = getRotatedAlphabet(rotations);
  var encodedMessage = message.split('');

  for (int i = 0; i < message.length; i++) {
    encodedMessage[i] =
        rotateCharacter(encodedMessage[i], rotations)['character'] as String;
    // print('${encodedMessage[i]}');
  }

  return encodedMessage.join();
}

String encodeMessage(String message, int rotations) {
  var rotatedAlphabet = getRotatedAlphabet(rotations);
  var encodedMessage = message.split('');

  for (int i = 0; i < message.length; i++) {
    encodedMessage[i] =
        rotateCharacter(encodedMessage[i], rotations)['character'] as String;
  }

  message = encodedMessage.join();

  return message;
}

Map<String, Object> rotateCharacter(String c, int rotation) {
  int code = c.codeUnitAt(0);
  int newCode = code + rotation;

  if (newCode > 122) {
    newCode = newCode - 26;
  }

  return {'code': newCode, 'character': String.fromCharCode(newCode)};
}

/// Retorna um array com todas as letras do alfabeto com rotação aplicada de acordo com o parâmetro
Map<String, List<Object>> getRotatedAlphabet(int rotation) {
  List<String> originalAlphabet = getAlphabet();
  List<String> newAlphabet = [];
  List<int> newAlphabetCodes = [];

  for (String c in originalAlphabet) {
    var rotated = rotateCharacter(c, rotation);

    newAlphabet.add(rotated['character'] as String);
    newAlphabetCodes.add(rotated['code'] as int);
  }

  return {'alphabet': newAlphabet, 'codes': newAlphabetCodes};
}

/// Retorna um array com todas as letras originais do alfabeto latino
List<String> getAlphabet() {
  List<String> alphabet = [];

  // As letras do alfabeto estão no intervalo de 97 a 122
  for (int i = 97; i <= 122; i++) {
    alphabet.add(String.fromCharCode(i));
  }
  return alphabet;
}
