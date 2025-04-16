#pragma once
#include "RailFenceCipher.hpp"
#include "Utils.hpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


class BreakTranspositionCipher {
    private: 
        RailFenceCipher rails_fence;
        Utils utils;

        map<string, double> get_bigrams_frequency_in_text(string text) {
            map<string, double> frequency_bigram;

            int n = text.size();
            int count_bigrams = 0;
            for(int i=0; i<n-1; i++){
                if(!utils.is_aplha(text[i]) || !utils.is_aplha(text[i+1])) continue;
                count_bigrams++;
                string bi; bi.push_back(text[i]); bi.push_back(text[i+1]);
                for(auto &c:bi)
                    if('a' <= c && c <= 'z') c = c - 'a' + 'A';

                frequency_bigram[bi]++;
            }

            for(auto [bi, f]: frequency_bigram) {
                frequency_bigram[bi]/=count_bigrams;
            }

            return frequency_bigram;
        }

        double calculate_score(string & text) {
            map<string, double> bigrams_frequency = get_bigrams_frequency_in_text(text);
            
            double score = 0;

            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    string bigram; bigram += 'A' + i; bigram+= 'A'+j;
                    score += abs(bigrams_frequency[bigram] - utils.digrams_percent_occurrence[bigram[0]-'A'][bigram[1]-'A']);
                }
            }

            return score;
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

        string frequency_distribution(string cipher_text) {
            double best_score = utils.INF;
            int best_k = -1;
            string plain_text;

            int n = cipher_text.size();
            
            for(int k=2; k<=n; k++) {
                rails_fence = RailFenceCipher(k);
                string current_plain_text = rails_fence.decrypt(cipher_text);
                double current_score = calculate_score(current_plain_text);

                if(current_score < best_score) {
                    best_score = current_score;
                    plain_text = current_plain_text;
                    best_k = k;
                }
            }
            return plain_text;
        }
};