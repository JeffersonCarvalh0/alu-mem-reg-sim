# include "alucomponents.h"

OutBits Adder::makeOperation(const EntryBits &in) const {
    OutBits out;
    out.result = in.bitA ^ in.bitB;
    out.carryOut = out.result ^ in.carryIn;
    return out;
}

OutBits And::makeOperation(const EntryBits &in) const {
    OutBits out;
    out.result = in.bitA & in.bitB;
    out.carryOut = in.carryIn;
    return out;
}

OutBits Or::makeOperation(const EntryBits &in) const {
    OutBits out;
    out.result = in.bitA | in.bitB;
    out.carryOut = in.carryIn;
    return out;
}
