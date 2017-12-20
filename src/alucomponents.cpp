# include "alucomponents.h"

void Adder::operator () (const bit a, const bit b, const bit in) {
    result = a ^ b;
    carryOut = result ^ in;
}

void And::operator () (const bit a, const bit b) {
    result = a & b;
}

void Or::operator () (const bit a, const bit b) {
    result = a | b;
}

void OverflowDetection::operator () (const bit carryIn, const bit carryOut) {
    result = carryIn ^ carryOut;
}
