#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Logger {
    public:
        static void start(bool user_input) {
            cout << "Transposition and Substitution Ciphers - Computer Security - UnB\n";
            
            cout << "Select Option:\n\n";
            
            cout << "T - Change to " << (user_input ? "input from existing files" : "input from user") << "\n";
            cout << "0 - Stop\n";
            cout << "1A - Encrypt using Ceasar Cipher (substitution)\n";
            cout << "1B - Decrypt using Ceasar Cipher(substitution)\n";
            cout << "1C - Break shift cipher by brute force\n";
            cout << "1D - Break shift cipher by frequency distribution\n";
            cout << "2A - Encrypt using Columnar Permutation Cipher (transposition)\n";
            cout << "2B - Decrypt using Columnar Permutation Cipher (transposition)\n";
            cout << "2C - Break columnar permutation by brute force\n";
            cout << "2D - Break columnar permutation by frequency distribution\n";
        }  
        
        static void print_vector(vector<string> v) {
            for(auto s:v){
                cout << s << "\n";
            }
        }

        static void print_string(string s) {
            cout << s << '\n';
        }

        static void line_space() {
            cout << '\n';
        }
};