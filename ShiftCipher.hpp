#pragma once
#include <string>
using namespace std;

class ShiftCipher {
    private:
        int k;

        bool is_upper_case(char c) {
            return ('A' <= c && c <= 'Z');
        }
        bool is_lower_case(char c) {
            return ('a' <= c && c <= 'z');
        }

        char encrypt_char(char c) {
            if(is_upper_case(c)) {
                c = 'A' + (c - 'A' + k)%26; 
            } else if(is_lower_case(c)) {
                c = 'a' + (c - 'a' + k)%26;
            }

            return c;
        }

        char decrypt_char(char c) {
            if(is_upper_case(c)) {
                c = 'A' + (c - 'A' - k + 26)%26; 
            } else if(is_lower_case(c)) {
                c = 'a' + (c - 'a' - k + 26)%26;
            }
            return c;
        }


    public:
        ShiftCipher() {}

        ShiftCipher(int k) {
            this->k = k;
        }
        string encrypt(string message) {
            for(char &c: message) {
                c = encrypt_char(c);
            }
            return message;
        }
        
        string decrypt(string message) {
            for(char &c: message) {
                c =  decrypt_char(c);
            }
            return message;
        }

};