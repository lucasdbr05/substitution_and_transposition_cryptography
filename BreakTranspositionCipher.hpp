#include "RailFenceCipher.hpp"
#include "Utils.hpp"
#include <string>
#include <vector>
#include <math.h>
#pragma once
using namespace std;


class BreakTranspositionCipher {
    private: 
        RailFenceCipher rails_fence;

        vector<pair<double, string>> get_bigrams_frequency_in_descending_order(string cipher_text) {
            map<string, int> frequency_bigram;
            vector<pair<double, string>> sorted_frequency;
            int n = cipher_text.size();
            int count_bigrams = 0;
            for(int i=0; i<n-1; i++){
                if(cipher_text[i]==' ' || cipher_text[i+1]==' ') continue;
                count_bigrams++;
                string bi; bi.push_back(cipher_text[i]); bi.push_back(cipher_text[i+1]);
                for(auto &c:bi)
                    if('a' <= c && c <= 'z') c = c - 'a' + 'A';

                frequency_bigram[bi]++;
            }

            for(auto [bi, f]: frequency_bigram) {
                sorted_frequency.push_back({f/((double)count_bigrams), bi});
            }

            sort(sorted_frequency.begin(), sorted_frequency.end(), greater<pair<double, char>>());
            return sorted_frequency;
        }

        double calculate_score(const vector<pair<double, string>> &bigrams_frequency) {
            double score = 0;

            for(auto [f, bigram]: bigrams_frequency) {
                if(f==0) break;
                score += abs(f - digrams_percent_occurrence[bigram[0]-'A'][bigram[1]-'A']);
            }

            score /=26;
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
            double best_score = INT32_MAX;
            int best_k = -1;
            string plain_text;

            int n = cipher_text.size();
            
            for(int k=2; k<=n; k++) {
                rails_fence = RailFenceCipher(k);
                string current_plain_text = rails_fence.decrypt(cipher_text);
                vector<pair<double, string>> sorted_frequency = get_bigrams_frequency_in_descending_order(cipher_text);
                double current_score = calculate_score(sorted_frequency);

                if(current_score < best_score) {
                    best_score = current_score;
                    plain_text = current_plain_text;
                    best_k = k;
                }
            }
            return plain_text;
        }
};