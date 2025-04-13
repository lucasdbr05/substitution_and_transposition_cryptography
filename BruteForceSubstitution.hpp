#include <ShiftCipher.hpp>
#include <string>
#include <vector>
using namespace std;


class BruteForceSubtitution {
    private: 
        ShiftCipher shiftCipher;

        vector<char> mostCommonLetters = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'U', 'C', 
            'M', 'W', 'F', 'G', 'Y', 'P', 'B', 'V', 'K', 'J', 'Z', 'X', 'Q'};
        
    public:
        BruteForceSubtitution () {}

        vector<string> breakChipher(string chipherText) {
            vector<string> res;
            for(int i=0; i<26; i++) {
                int k = (mostCommonLetters[i] - 'A');
                
                shiftCipher = ShiftCipher(k);
                res.push_back(
                    shiftCipher.decrypt(chipherText)
                );
            }     
            return res;
        }
};