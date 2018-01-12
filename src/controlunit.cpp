# include "controlunit.h"

ControlUnit::ControlUnit() : aluControl(aluControl) {
    op = vector<bit>(OP_SIZE);
}

void ControlUnit::process() {
    bit and1, and2, and3, and4, or1, or2;

    and1 = (!op[0] && !op[1] && !op[2] && !op[3] && !op[4] && !op[5]);
    and2 = (op[0] && op[1] && !op[2] && !op[3] && !op[4] && op[5]);
    and3 = (op[0] && op[1] && !op[2] && op[3] && !op[4] && op[5]);
    and4 = (!op[0] && !op[1] && op[2] && !op[3] && !op[4] && !op[5]);

    or1 = (and2 || and3);
    or2 = (and1 || and2);

    regDst = and1;
    aluSrc = or1;
    memToReg = and2;
    regWrite = or2;
    memRead = and2;
    memWrite = and3;
    branch = and4;
    aluOp1 = and1;
    aluop0 = and4;
}

ALUContol::ALUControl() {
    funct = vector<bit>(FUNCT_SIZE);
}

// void ALUControl::process() {
//     op0 =
// }
