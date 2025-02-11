#define  ENCRYPTPLAINTEXT_H
#ifndef ENCRYPTPLAINTEXT_H

#include <iostream>
#include <string>

class EncryptPlaintext {
 public:
    std::string round_key[16];
    std::string pt;

    std::string convertDecimalToBinary(int decimal);

    int convertBinaryToDecimal(std::string binary);

    string Xor(string a, string b);

    void generate_keys(string key);

    string DES();

    int subsititution_boxes[8][4][16];
    int permutation_tab[32];
    int inverse_permutation[64];
};

#endif