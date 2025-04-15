#include "ShiftCipher.hpp"
#include "Utils.hpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#pragma once
using namespace std;


class BreakSubstitutionCipher {
    private: 
        ShiftCipher shift_cipher;
        
        int calculate_key(int c, int iht_most_frequent) {
            return (c - most_frequent_letters[iht_most_frequent] + 26) % 26;
        }

        vector<pair<double, char>> get_letters_frequency_in_descending_order(string text) {
            map<char, double> frequency_letter;
            vector<pair<double, char>> sorted_frequency;
            int n = text.size();
            int count_letter = 0;
            for(auto c: text){
                if(c==' ') continue;
                count_letter++;

                if('a' <= c && c <= 'z') c = c - 'a' + 'A';
                frequency_letter[c]++;
            }

            for(auto [c, f]: frequency_letter) {
                sorted_frequency.push_back({f/count_letter, c});
            }

            sort(sorted_frequency.begin(), sorted_frequency.end(), greater<pair<double, char>>());
            return sorted_frequency;
        }

        double calculate_score(const string& text) {
            vector<pair<double, char>> letters_sorted_frequency = get_letters_frequency_in_descending_order(text);
            
            double score = 0;

            for(auto [f, letter]: letters_sorted_frequency) {
                score += abs(f - letter_percent_occurrence[letter-'A']);
            }

            score /=26;
            return score;
        }

    public:
        BreakSubstitutionCipher () {}

        vector<string> brute_force(string cipher_text) {
            vector<string> res;
            for(int k=0; k<26; k++) {                
                shift_cipher = ShiftCipher(k);
                res.push_back(
                    shift_cipher.decrypt(cipher_text)
                );
            }     
            return res;
        }
        
        string frequency_distribution(string cipher_text) {
            double best_score = INT32_MAX;
            int best_k = -1;
            string plain_text;

            vector<pair<double, char>> sorted_frequency = get_letters_frequency_in_descending_order(cipher_text);
        
            for(int i=0; i*i<26; i++) {
                int k = calculate_key(sorted_frequency[0].second, i);
                shift_cipher = ShiftCipher();
                string current_plain_text = shift_cipher.decrypt(cipher_text);
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