#include "ShiftCipher.hpp"
#pragma once
using namespace std;

class CeasarCipher : public ShiftCipher {
    public:
        CeasarCipher():
            ShiftCipher(3) {}
};