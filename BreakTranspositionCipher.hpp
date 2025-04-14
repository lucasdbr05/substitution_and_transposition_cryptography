#include "RailFenceCipher.hpp"
#include "Utils.hpp"
#include <string>
#include <vector>
#pragma once
using namespace std;


class BreakTranspositionCipher {
    private: 
        RailFenceCipher rails_fence;

    public:
        BreakTranspositionCipher () {}

        vector<string> brute_force(string cipher_text) {
            vector<string> res;
            int n = cipher_text.size();
            for(int k=2; k<=n; k++) {
                
                rails_fence = RailFenceCipher(k);
                res.push_back(
                    rails_fence.decrypt(cipher_text)
                );
            }     
            return res;
        }

        vector<string> frequency_distribution(string cipher_text) {
            vector<string> res;
            
            return res;
        }
};