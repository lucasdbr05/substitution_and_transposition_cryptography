#include "RailFenceCipher.hpp"
#include <string>
#include <vector>
#pragma once
using namespace std;


class BruteForceTransposition {
    private: 
        RailFenceCipher railsFence;

    public:
        BruteForceTransposition () {}

        vector<string> breakChipher(string chipherText) {
            vector<string> res;
            int n = chipherText.size();
            for(int k=2; k<=n; k++) {
                
                railsFence = RailFenceCipher(k);
                res.push_back(
                    railsFence.decrypt(chipherText)
                );
            }     
            return res;
        }
};