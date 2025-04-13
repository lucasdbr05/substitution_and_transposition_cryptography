#include "ShiftCipher.hpp"
#include <string>
#include <vector>
#pragma once
using namespace std;


class BruteForceSubtitution {
    private: 
        ShiftCipher shiftCipher;

    public:
        BruteForceSubtitution () {}

        vector<string> breakChipher(string chipherText) {
            vector<string> res;
            for(int k=0; k<26; k++) {                
                shiftCipher = ShiftCipher(k);
                res.push_back(
                    shiftCipher.decrypt(chipherText)
                );
            }     
            return res;
        }
};