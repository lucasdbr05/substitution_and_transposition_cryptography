#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class ColumnarPermutationCipher {
    private:
        string key;
        int key_size;
        vector<vector<char>> t_matrix;

        void permute_columns() {
            vector<vector<char>> new_matrix(key_size);
            vector<pair<char, int>> letter_by_column(key_size);
            for(int i=0; i<key_size; i++) {
                letter_by_column[i] = {key[i], i};
            }
            sort(letter_by_column.begin(), letter_by_column.end());

            for(int i=0; i<key_size; i++){
                new_matrix[i] = t_matrix[letter_by_column[i].second];
            }
            t_matrix = new_matrix;
            
            return;
        }
        void invert_permute_columns() {
            vector<vector<char>> new_matrix(key_size);
            vector<pair<char, int>> letter_by_column(key_size);
            for(int i=0; i<key_size; i++) {
                letter_by_column[i] = {key[i], i};
            }
            sort(letter_by_column.begin(), letter_by_column.end());

            for(int i=0; i<key_size; i++){
                new_matrix[letter_by_column[i].second] = t_matrix[i];                
            }
            t_matrix = new_matrix;
            
            return;
        }

        void padding(string& s){
            int padding_size = (key_size - s.size()%key_size) % key_size;
            while(padding_size--) s += ' ';
        }

        string build_cipher_text(int rows) {
            string text = "";
            for(int i=0; i<key_size; i++){
                for(int j=0; j<rows; j++){
                    text+= t_matrix[i][j];
                }
            }
            return text;
        }

        string build_plain_text(int rows) {
            string text = "";
            for(int j=0; j<rows; j++){
                for(int i=0; i<key_size; i++){
                    text+= t_matrix[i][j];
                }
            }
            return text;
        }

    public:
        ColumnarPermutationCipher(){}
        
        ColumnarPermutationCipher(string key) {
            this->key = key;
            this->key_size = key.size();
        }

        string encrypt(string plain_text) {
            int rows = plain_text.size()/key_size + (plain_text.size()%key_size > 0);
            t_matrix = vector(key_size, vector<char>(rows, ' '));
            padding(plain_text);

            for(int i=0; i<rows; i++){
                for(int j=0; j<key_size; j++){
                    int current_char = i*key_size + j;
                    
                    t_matrix[j][i] = plain_text[current_char];
                }
            }
            
            permute_columns();
                      
            return build_cipher_text(rows);
        }
        
        string decrypt(string cipher_text) {
            int rows = cipher_text.size()/key_size + (cipher_text.size()%key_size > 0);
            t_matrix = vector(key_size, vector<char>(rows, ' '));
            padding(cipher_text);
            
            int current_char =0;
            for(int j=0; j<key_size; j++){
                for(int i=0; i<rows; i++){
                    t_matrix[j][i] = cipher_text[current_char];
                    current_char++;
                }
            }
                    
            invert_permute_columns();       
            return build_plain_text(rows);    
        }
};