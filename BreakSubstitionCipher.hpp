#include "ShiftCipher.hpp"
#include <string>
#include <vector>
#pragma once
using namespace std;


class BreakSubstitutionCipher {
    private: 
        ShiftCipher shift_cipher;

    public:
        BreakSubstitutionCipher () {}

        vector<string> brute_force(string chipherText) {
            vector<string> res;
            for(int k=0; k<26; k++) {                
                shift_cipher = ShiftCipher(k);
                res.push_back(
                    shift_cipher.decrypt(chipherText)
                );
            }     
            return res;
        }
};