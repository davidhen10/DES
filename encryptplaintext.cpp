#include "EncryptPlaintext.h"
#include "Generate.h"
#include <cmath>

using namespace std;

string round_keys[16];
string pt;

string EncryptPlaintext::convertDecimalToBinary(int decimal) {
    string binary = "";
    for (int i = 0; i < 4; i++) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

int EncryptPlaintext::convertBinaryToDecimal(string binary) {
    int decimal = 0;
    for (int i = 0; i < binary.length(); i++) {
        decimal += (binary[i] - '0') * pow(2, binary.length() - 1 - i);
    }
    return decimal;
}

