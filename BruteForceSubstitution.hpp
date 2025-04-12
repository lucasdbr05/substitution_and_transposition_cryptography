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
        void breakChipher(string chipherText) {
            for(int i=0; i<26; i++) {
                int k = (mostCommonLetters[i] - 'A');
                
                shiftCipher = ShiftCipher(k);
                shiftCipher.decrypt(chipherText);
            }        
        }
};