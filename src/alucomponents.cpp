# include "alucomponents.h"
# include <iostream>

using namespace std;

void Adder::operator () (const bit a, const bit b, const bit in) {
    result = (a & !b & !in) | (!a & b & !in) | (!a & !b & in) | (a & b & in);
    carryOut = (b & in) | (a & in) | (a & b);
    cout << "BitA: " << a << " BitB: " << b << " CarryIn: " << in << '\n';
    cout << "Result: " << result << " CarryOut: " << carryOut << "\n\n";
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
