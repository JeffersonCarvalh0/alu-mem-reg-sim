# include "alu.h"

void ALU::muxSelect() {
    // Inverts bitA if AInvert is set to 1
    if (AInvert)
        in.bitA = bitA ? 0 : 1;
    // Inverts bitB if BInvert is set to 1
    if (BInvert)
        in.bitB = bitB ? 0 : 1;
}

virtual void ALU::process(const ResultOptions result, bit less) {
    muxSelect(); // Will invert A or B if necessary
    adder(a, b);
    and(a, b);
    or(a, b);

    carryOut = adder.carryOut;

    switch (result) {
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
    ov();

    set = adder.result;
    overflow = ov.result;
}
