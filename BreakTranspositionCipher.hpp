#include "RailFenceCipher.hpp"
#include "Utils.hpp"
#include <string>
#include <vector>
#pragma once
using namespace std;


class BreakTranspositionCipher {
    private: 
        RailFenceCipher rails_fence;

        vector<pair<int, string>> get_bigrams_frequency_in_descending_order(string cipher_text) {
            map<string, int> frequency_bigram;
            vector<pair<int, string>> sorted_frequency;
            int n = cipher_text.size();
            for(int i=0; i<n-1; i++){
                if(cipher_text[i]==' ' || cipher_text[i+1]==' ') continue;
                string bi; bi.push_back(cipher_text[i]); bi.push_back(cipher_text[i+1]);
                for(auto &c:bi)
                    if('a' <= c && c <= 'z') c = c - 'a' + 'A';

                frequency_bigram[bi]++;
            }

            for(auto [bi, f]: frequency_bigram) {
                sorted_frequency.push_back({f, bi});
            }

            sort(sorted_frequency.begin(), sorted_frequency.end(), greater<pair<int, char>>());
            return sorted_frequency;
        }
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