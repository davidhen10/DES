#define GENERATE.H
#ifndef GENERATE_H

#include <iostream>
#include <string>

class Generate {
public:
    std::string round_key[16];

    std::string shift_left_once(std::string key_chunk);

    std::string shift_left_twice(std::string key_chunk);

    void generate_keys(std::string key);

    std::string perm_key;

    std::string left;
    std::string right;

    std::string combined_key;
    std::string round_key;
};

#endif