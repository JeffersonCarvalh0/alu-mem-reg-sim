# include "datapath.h"
# include "controlunit.h"
# include "fullalu.h"
# include "mainmemory.h"
# include "registers.h"
# include "utils.h"
# include <vector>
# include <iostream>

using namespace std;

vector<bit> MinorDevices::signExtend(const vector<bit> &in) {
    vector<bit> out(WORD);

    for (int i = CONST_SIZE; i < WORD; ++i)
        out[i] = in[i];

    for (int i = 0; i < CONST_SIZE; ++i)
        out[i] = 0;

    return out;
}

Datapath::Datapath(RegisterBank *reg, ControlUnit *control,
    ALUControl *aluControl, FullALU *alu, MainMemory *mem, MinorDevices *others):
    registerBank(reg), control(control), alu(alu), mem(mem), others(others) {};

void Datapath::getInstruction(const vector<bit> &instruction) {
    this->instruction = instruction;
}

void Datapath::processInstruction() {
    vector<bit> op, rs, rt, rd, shamt, funct, con;
    rs = rt = rd = vector<bit>(ADDR_BUS_SIZE);
    op = vector<bit>(OP_SIZE);
    shamt = vector<bit>(SHAMT_SIZE);
    con = vector<bit>(CONST_SIZE);

    for (int i = 0; i <= ADDR_BUS_SIZE; ++i) {
        // Set the addresses
        rs[i] = instruction[i + 6];
        rt[i] = instruction[i + 11];
        rd[i] = instruction[i + 16];
    }

    for (int i = 0; i <= OP_SIZE; ++i)
        // Set the op field
        op[i] = instruction[i];

    for (int i = 0; i <= SHAMT_SIZE; ++i)
        // Set the shift amount field
        shamt[i] = instruction[i + 21];

    for (int i = 0; i < FUNCT_SIZE; ++i)
        // Set the funct field
        funct[i] = instruction[i + 26];

    for (int i = 0; i < CONST_SIZE; ++i)
        con[i] = instruction[i + 16];

    // ControlUnit
    control->op = op;
    control->process();

    // MinorDevices
    others->regInMux = control->regDst;
    others->aluInMux = control->aluSrc;
    others->memOutMux = control->memToReg;

    // ALUControl
    aluControl->aluOp0 = control->aluOp0;
    aluControl->aluOp1 = control->aluOp1;
    aluControl->funct = funct;
    aluControl->process();

    // RegisterBank
    registerBank->regWrite = control->regWrite;
    registerBank->readReg1 = rs;
    registerBank->readReg2 = rt;
    registerBank->writeReg = (others->regInMux) ? shamt : rt;
    registerBank->read();

    // ALU
    alu->AInvert = aluControl->AInvert;
    alu->BNegate = aluControl->BNegate;
    alu->operation = bitsToResOp(aluControl->op1, aluControl->op2);
    alu->inputA = registerBank->readData1;
    alu->inputB = (others->aluInMux) ? others->signExtend(con) : registerBank->readData2;
    alu->process();

    // Main memory
    mem->memWrite = control->memWrite;
    mem->memRead = control->memRead;
    mem->address = alu->result;
    mem->writeData = registerBank->readData2;
    mem->process();

    // RegisterBank again
    registerBank->writeData = (others->memOutMux) ? mem->readData : alu->result;
    registerBank->write();
}

void Datapath::showRegData() {
    cout << "##################################################################";
    cout << "Register Bank:\n\n";

    cout << "Inputs:\n";
    cout << "Read Register 1:\n";
    printVec(registerBank->readReg1);
    cout << "\n(" << bitVecToInt(registerBank->readReg1) << " decimal)\n";

    cout << "\nRead Register 2:\n";
    printVec(registerBank->readReg2);
    cout << "\n(" << bitVecToInt(registerBank->readReg2) << " decimal)\n";

    cout << "\nWrite Register:\n";
    printVec(registerBank->writeReg);
    cout << "\n(" << bitVecToInt(registerBank->writeReg) << "decimal)\n";

    cout << "\nWrite Data\n:";
    printVec(registerBank->writeData);
    cout << "\n(" << bitVecToInt(registerBank->writeData) << "decimal)\n\n";

    cout << "Control Lines:\n";
    cout << "RegWrite: " << registerBank->regWrite << "\n\n";

    cout << "Outputs\n";
    cout << "Read Data 1:\n";
    printVec(registerBank->readData1);
    cout << "\n(" << bitVecToInt(registerBank->readData1) << "decimal)\n";

    cout << "Read Data 2:\n";
    printVec(registerBank->readData2);
    cout << "\n(" << bitVecToInt(registerBank->readData2) << "decimal)\n\n";
}

void Datapath::showALUData() {
    cout << "##################################################################";
    cout << "ALU:\n\n";

    cout << "Inputs:\n";
    cout << "Input A:\n";
    printVec(alu->inputA);
    cout << "\n(" << bitVecToInt(alu->inputA) << " decimal)\n";

    cout << "\nInput B:\n";
    printVec(alu->inputB);
    cout << "\n(" << bitVecToInt(alu->inputB) << " decimal)\n";

    cout << "Control Lines:\n";
    cout << "AInvert: " << alu->AInvert << "\n";
    cout << "BNegate: " << alu->BNegate << "\n";
    cout << "Operation: " << resOpToStr(alu->operation) << "\n\n";

    cout << "Outputs\n";
    cout << "Read Data 1:\n";
    printVec(registerBank->readData1);
    cout << "\n(" << bitVecToInt(registerBank->readData1) << "decimal)\n";

    cout << "Read Data 2:\n";
    printVec(registerBank->readData2);
    cout << "\n(" << bitVecToInt(registerBank->readData2) << "decimal)\n\n";
}

void Datapath::showMainMemData() {
    cout << "##################################################################";
    cout << "Main Memory:\n\n";

    cout << "Inputs:\n";
    cout << "Address:\n";
    printVec(mem->address);
    cout << "\n(" << bitVecToInt(mem->address) << " decimal)\n";

    cout << "\nWrite Data:\n";
    printVec(mem->writeData);
    cout << "\n(" << bitVecToInt(mem->writeData) << " decimal)\n";

    cout << "Control Lines:\n";
    cout << "MemWrite: " << mem->memWrite << "\n";
    cout << "MemRead: " << mem->memRead << "\n\n";

    cout << "Outputs\n";
    cout << "Read Data:\n";
    printVec(mem->readData);
    cout << "\n(" << bitVecToInt(mem->readData) << "decimal)\n";
}
