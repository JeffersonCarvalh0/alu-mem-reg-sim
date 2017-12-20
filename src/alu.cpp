# include "alu.h"

void ALU::muxSelect() {
    // Inverts bitA if AInvert is set to 1
    if (AInvert)
        a = a ? 0 : 1;
    // Inverts bitB if BInvert is set to 1
    if (BInvert)
        b = b ? 0 : 1;
}

void ALU::process(const ResultOptions option) {
    muxSelect(); // Will invert A or B if necessary
    adder(a, b, carryIn);
    andGate(a, b);
    orGate(a, b);

    carryOut = adder.carryOut;

    switch (option) {
        case AND:
            result = andGate.result;
            break;
        case OR:
            result = orGate.result;
            break;
        case SUM:
            result = adder.result;
            break;
        case LESS:
            result = less;
            break;
    }
}

void MSALU::process(const ResultOptions result) {
    ALU::process(result);
    ov(carryIn, carryOut);

    set = adder.result;
    overflow = ov.result;
}
