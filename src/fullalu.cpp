# include "fullalu.h"

using namespace std;

FullALU::FullALU() {
    aluArr = vector<ALU*>(BITS);
    for (int i = 0; i < BITS - 1; ++i)
        aluArr[i] = new ALU();
    aluArr[BITS - 1] = new MSALU();

    result = vector<bit>(BITS, 0);
}

inline void FullALU::setBits(const int i, const bit lastCarryOut) const {
    aluArr[i]->AInvert = AInvert;
    aluArr[i]->BInvert = BNegate;
    aluArr[i]->carryIn = lastCarryOut;
    aluArr[i]->a = inputA[i];
    aluArr[i]->b = inputB[i];
    aluArr[i]->less = 0;
}

void FullALU::process() {
    bit lastCarryOut = BNegate;

    for (int i = 0; i < BITS; ++i) {
        setBits(i, lastCarryOut);
        aluArr[i]->process(operation);
        result[i] = aluArr[i]->result;
        lastCarryOut = aluArr[i]->carryOut;
    }

    overflow = static_cast<MSALU*>(aluArr[BITS - 1])->result;
    aluArr[0]->less = static_cast<MSALU*>(aluArr[BITS - 1])->set;
    aluArr[0]->process(operation);
    result[0] = aluArr[0]->result;
}
