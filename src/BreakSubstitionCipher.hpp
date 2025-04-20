#pragma once
#include "ShiftCipher.hpp"
#include "Utils.hpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;



/**
 * @class BreakSubstitutionCipher
 * @brief A class designed to break substitution ciphers using 
 *  frequency analysis and brute force methods.
 */
class BreakSubstitutionCipher {
    private: 
        ShiftCipher shift_cipher;
        Utils utils;

        int calculate_key(int c, int iht_most_frequent) {
            return (c - utils.most_frequent_letters[iht_most_frequent] + 26) % 26;
        }

        map<char, double> get_letters_frequency_in_text(string text) {
            map<char, double> frequency_letter;
            int n = text.size();
            int count_letter = 0;

            for(auto c: text){
                if(!utils.is_aplha(c)) continue;
                count_letter++;
                
                if('a' <= c && c <= 'z') c = c - 'a' + 'A';
                frequency_letter[c]++;
            }

            for(auto [c, f]: frequency_letter) {
                frequency_letter[c]/=count_letter;
            }
            
            return frequency_letter;
        }

        vector<pair<double, char>> get_letters_frequency_in_descending_order(
            map<char, double>& frequency_letter
        ){
            vector<pair<double, char>> sorted_frequency;
            for(auto [c, f]: frequency_letter) {
                sorted_frequency.push_back({f, c});
            }

            sort(sorted_frequency.begin(), sorted_frequency.end(), greater<pair<double, char>>());
            return sorted_frequency;
        }

        
        /**
         * @brief Calculates a score for the given text based on letter frequency analysis.
         * @param text The input text to evaluate.
         * @return The calculated score, where a lower score indicates a closer match to expected letter frequencies.
         */
        double calculate_score(string& text) {
            map<char, double> letters_frequency = get_letters_frequency_in_text(text);            
            double score = 0;

            for(int i=0; i<26; i++) {
                score += abs(letters_frequency['A'+i] - utils.letter_percent_occurrence[i]);
            } 
            return score;
        }

    public:
        BreakSubstitutionCipher () {}

        /**
         * @brief Attempts to decrypt the cipher text using a brute force approach by trying all possible keys.
         * @param cipher_text The encrypted text to decrypt.
         * @return A vector of all possible decrypted texts for each key.
         */
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
        
        /**
         * @brief Decrypts the cipher text using frequency distribution analysis to find the most likely plain text.
         * @param cipher_text The encrypted text to decrypt.
         * @return The decrypted plain text with the best score based on frequency analysis.
         */
        string frequency_distribution(string cipher_text) {
            double best_score = utils.INF;
            int best_k = -1;
            string plain_text;

            map<char, double> frequency = get_letters_frequency_in_text(cipher_text);
            vector<pair<double, char>> sorted_frequency = get_letters_frequency_in_descending_order(frequency);
            
            for(int i=0; i*i<26; i++) {
                int k = calculate_key(sorted_frequency[0].second, i);
                shift_cipher = ShiftCipher(k);
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