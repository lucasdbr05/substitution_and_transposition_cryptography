#include <ShiftCipher.hpp>
using namespace std;

class CeasarCipher : public ShiftCipher {
    public:
        CeasarCipher():
            ShiftCipher(3) {}
};