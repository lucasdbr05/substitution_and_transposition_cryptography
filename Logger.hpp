#include <iostream>
#include <vector>
#include <string>
#pragma once
using namespace std;

class Logger {
    public:
        static void start() {
            cout << "Transposition and Substitution Ciphers - Computer Security - UnB\n";

            cout << "Select Option:\n";

            cout << "1A - Encrypt using Ceasar Cipher (substitution)\n";
            cout << "1B - Decrypt using Ceasar Cipher(substitution)\n";
            cout << "1C - Break shift cipher by brute force\n";
            cout << "1D - Break shift cipher by frequency distribution\n";
            cout << "2A - Encrypt using Rails Fence Cipher (transposition)\n";
            cout << "2B - Decrypt using Rails Fence Cipher (transposition)\n";
            cout << "2C - Break rails fence by brute force\n";
            cout << "2D - Break rails fece by frequency distribution\n";
            cout << "0 - Stop\n";
        }  
        
        static void print_vector(vector<string> v) {
            for(auto s:v){
                cout << s << "\n";
            }
        }

        static void print_string(string s) {
            cout << s << '\n';
        }
};