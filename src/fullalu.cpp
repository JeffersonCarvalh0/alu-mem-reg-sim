# include "fullalu.h"

using namespace std;

FullALU::FullALU() {
    aluArr = vector<ALU*>(WORD);
    for (int i = WORD - 1; i > 0; --i)
        aluArr[i] = new ALU();
    aluArr[0] = new MSALU();

    result = vector<bit>(WORD);
    zero = 0;
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

    for (int i = WORD - 1; i > 0; --i) {
        setBits(i, lastCarryOut);
        aluArr[i]->process(operation);
        result[i] = aluArr[i]->result;
        lastCarryOut = aluArr[i]->carryOut;
        zero |= result[i];
    }

    // Operations for the MSALU
    setBits(0, lastCarryOut);
    static_cast<MSALU*>(aluArr[0])->process(operation);
    result[0] = aluArr[0]->result;
    zero |= result[0];
    zero = !zero;

    // Overflow detection and slt
    overflow = static_cast<MSALU*>(aluArr[0])->overflow;
    aluArr[WORD - 1]->less = static_cast<MSALU*>(aluArr[0])->set;
    aluArr[WORD - 1]->AInvert = aluArr[WORD - 1]->BInvert = false;
    aluArr[WORD - 1]->process(operation);
    result[WORD - 1] = aluArr[WORD - 1]->result;
}
