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

        vector<pair<int, char>> get_words_frequency_in_descending_order(string cipher_text) {
            map<char, int> frequency_letter;
            vector<pair<int, char>> sorted_frequency;
            int n = cipher_text.size();
            for(auto c:cipher_text){
                if('a' <= c && c <= 'z') c = c - 'a' + 'A';
                frequency_letter[c]++;
            }

            for(auto [c, f]: frequency_letter) {
                sorted_frequency.push_back({f, c});
            }

            sort(sorted_frequency.begin(), sorted_frequency.end(), greater<pair<int, char>>());
            return sorted_frequency;
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
        
        vector<string> frequency_distribution(string cipher_text) {
            vector<string> res;
            
            vector<pair<int, char>> sorted_frequency = get_words_frequency_in_descending_order(cipher_text);
        
            for(int i=0; i<26; i++) {
                shift_cipher = ShiftCipher(calculate_key(sorted_frequency[i].second, i));
                res.push_back(shift_cipher.decrypt(cipher_text));
            }
            return res;
        }
};