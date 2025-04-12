#include <ShiftCipher.hpp>
using namespace std;

class CeasarCipher : public ShiftCipher {
    CeasarCipher():
         ShiftCipher(3) {}
};