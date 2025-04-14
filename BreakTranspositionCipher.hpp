#include "RailFenceCipher.hpp"
#include <string>
#include <vector>
#pragma once
using namespace std;


class BreakTranspositionCipher {
    private: 
        RailFenceCipher rails_fence;

    public:
        BreakTranspositionCipher () {}

        vector<string> brute_force(string chipherText) {
            vector<string> res;
            int n = chipherText.size();
            for(int k=2; k<=n; k++) {
                
                rails_fence = RailFenceCipher(k);
                res.push_back(
                    rails_fence.decrypt(chipherText)
                );
            }     
            return res;
        }
};