# include "controlunit.h"
# include <iostream>

using namespace std;

using namespace std;

ControlUnit::ControlUnit() {
    op = vector<bit>(OP_SIZE);
}

void ControlUnit::process() {
    bit rFormat, lw, sw, beq, addi, and1, or1, or2;

    rFormat = (!op[0] & !op[1] & !op[2] & !op[3] & !op[4] & !op[5]);
    lw = (op[0] & op[1] & !op[2] & !op[3] & !op[4] & op[5]);
    sw = (op[0] & op[1] & !op[2] & op[3] & !op[4] & op[5]);
    beq = (!op[0] & !op[1] & op[2] & !op[3] & !op[4] & !op[5]);
    addi = (!op[0] & !op[1] & !op[2] & op[3] & !op[4] & !op[5]);

    and1 = (rFormat & !addi);
    or1 = (lw | sw | addi);
    or2 = (rFormat | lw | addi);

    regDst = and1;
    aluSrc = or1;
    memToReg = lw;
    regWrite = or2;
    memRead = lw;
    memWrite = sw;
    branch = beq;
    aluOp1 = rFormat;
    aluOp0 = beq;
}

ALUControl::ALUControl() {
    funct = vector<bit>(FUNCT_SIZE);
}

void ALUControl::process() {
    // 4 bits - AInvert, BNegate, op1 and op2
    AInvert = (aluOp0 & !aluOp0);
    BNegate = (aluOp0 | (aluOp1 & funct[1]));
    op1 = (!aluOp1 | !funct[2]);
    op2 = (aluOp1 & (funct[3] | funct[0]));
}
