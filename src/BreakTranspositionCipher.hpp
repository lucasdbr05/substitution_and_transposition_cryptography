#pragma once
#include "ColumnarPermutationCipher.hpp"
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
        ColumnarPermutationCipher permutation_cipher;
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
            int max_cols = 8;

            for(int key_size=2; key_size<= min(max_cols, 26); key_size++) {
                string key = utils.alphabet.substr(0, key_size);
                
                do {
                    permutation_cipher = ColumnarPermutationCipher(key);

                    res.push_back(
                        permutation_cipher.decrypt(cipher_text)
                    );
                } while(
                    next_permutation(key.begin(), key.end())
                );
            }     
            return res;
        }

        string frequency_distribution(string cipher_text) {
            double best_score = utils.INF;
            string best_key;
            string plain_text;

            int n = cipher_text.size();
            int max_cols = 8;

            for(int key_size=2; key_size<=min(max_cols, 26); key_size++) {
                string key = utils.alphabet.substr(0, key_size);
                
                do {
                    permutation_cipher = ColumnarPermutationCipher(key);
                    string current_plain_text = permutation_cipher.decrypt(cipher_text);
                    
                    double current_score = calculate_score(current_plain_text);
    
                    if(current_score < best_score) {
                        best_score = current_score;
                        plain_text = current_plain_text;
                        best_key = key;
                    }
                } while(
                    next_permutation(key.begin(), key.end())
                );
                
            }
            return plain_text;
        }
};