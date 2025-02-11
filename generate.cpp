#include "Generate.h"

using namespace std;

string Generate::shift_left_once(string key_chunk) {
    string shifted = "";
    for (int i = 1; i < 28; i++) {
        shifted += key_chunk[i];
    }
    shifted += key_chunk[0];
    return shifted;
}

string Generate::shift_left_twice(string key_chunk) {
    string shifted = "";
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 28; j++) {
            shifted += key_chunk[j];
        }
        shifted += key_chunk[0];
        key_chunk = shifted;
        shifted = "";
    }
    return key_chunk;
}

void Generate::generate_keys(string key) {
    // The PC1 table
    int pc1[56] = {
            57, 49, 41, 33, 25, 17, 9,
            1, 58, 50, 42, 34, 26, 18,
            10, 2, 59, 51, 43, 35, 27,
            19, 11, 3, 60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15,
            7, 62, 54, 46, 38, 30, 22,
            14, 6, 61, 53, 45, 37, 29,
            21, 13, 5, 28, 20, 12, 4
    };
    // The PC2 table
    int pc2[48] = {
            14, 17, 11, 24, 1, 5,
            3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8,
            16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32
    };
    // 1. Compressing the key using the PC1 table
    perm_key = "";
    for (int i = 0; i < 56; i++) {
        perm_key += key[pc1[i] - 1];
    }
    // 2. Dividing the result into two equal halves
    left = perm_key.substr(0, 28);
    right = perm_key.substr(28, 28);
    // Generating 16 keys
    for (int i = 0; i < 16; i++) {
        if (i == 0 || i == 1 || i == 8 || i == 15) {
            // Performing a circular left shift
            left = shift_left_once(left);
            right = shift_left_once(right);
        } else {
            // Performing a circular left shift twice
            left = shift_left_twice(left);
            right = shift_left_twice(right);
        }
    }

string combined_key = left + right;
string round_key = "";

for (int i = 0; i < 48; i++) {
    round_key += combined_key[pc2[i] - 1];
}
round_keys[i] = round_key;
    cout << "Key " << i + 1 << " is: " << round_keys[i] << endl;
}