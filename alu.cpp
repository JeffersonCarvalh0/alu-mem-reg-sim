# include "alu.h"

void EntryBits::operator = (EntryBits &in) {
    this->carryIn = in.carryIn;
    this->bitA = in.bitA;
    this->bitB = in.bitB;
}

void ALU::setInBits(const EntryBits &in) {
    this->in = in;
    muxSelect();
}

void ALU::muxSelect() {
    if (AInvert)
        in.bitA = bitA ? 0 : 1;
    if (BInvert)
        in.bitB = bitB ? 0 : 1;
}

OutBits ALU::add() {
    return adder.makeOperation(in);
}

OutBits ALU::andOp() {
    return andGate.makeOperation(in);
}

OutBits ALU::orOp() {
    return orGate.makeOperation(in);
}
