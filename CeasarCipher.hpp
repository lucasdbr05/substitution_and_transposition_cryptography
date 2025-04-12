#include <string>
using namespace std;

class CeasarCipher {
    private:
        int k = 3;

        bool isUpperCase(char c) {
            return ('A' <= c && c <= 'Z');
        }
        bool isLowerCase(char c) {
            return ('a' <= c && c <= 'z');
        }

        char encryptChar(char c) {
            if(isUpperCase(c)) {
                c = 'A' + (c - 'A' + k)%26; 
            } else if(isLowerCase(c)) {
                c = 'a' + (c - 'a' + k)%26;
            }

            return c;
        }

        char decryptChar(char c) {
            if(isUpperCase(c)) {
                c = 'A' + (c - 'A' - k + 26)%26; 
            } else if(isLowerCase(c)) {
                c = 'a' + (c - 'a' - k + 26)%26;
            }

            return c;
        }


    public:

        string encrypt(string message) {
            for(char &c: message) {
                c = encryptChar(c);
            }
            return message;
        }
        
        string decrypt(string message) {
            for(char &c: message) {
                c =  decryptChar(c);
            }
            return message;
        }

};