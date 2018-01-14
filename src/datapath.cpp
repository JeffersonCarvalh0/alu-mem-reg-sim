# include "datapath.h"
# include <vector>
# include <iostream>
# include <algorithm> // std::reverse

using namespace std;

vector<bit> MinorDevices::signExtend(const vector<bit> &in) {
    vector<bit> out(WORD);

    for (int i = CONST_SIZE; i < WORD; ++i)
        out[i] = in[i - CONST_SIZE];

    for (int i = 0; i < CONST_SIZE; ++i)
        out[i] = 0;

    return out;
}

Datapath::Datapath(RegisterBank *reg, ControlUnit *control,
    ALUControl *aluControl, FullALU *alu, MainMemory *mem, MinorDevices *others):
    registerBank(reg), control(control), aluControl(aluControl), alu(alu),
    mem(mem), others(others) {};

void Datapath::setInstruction(const vector<bit> &instruction) {
    this->instruction = instruction;
}

void Datapath::setInstruction(const string &instruction) {
    vector<bit> instructionVec(WORD);
    for (int i = 0; i < WORD; ++i)
        instructionVec[i] = (instruction[i] == '0') ? 0 : 1;
    this->instruction = instructionVec;
}

void Datapath::processInstruction() {
    vector<bit> op, rs, rt, rd, shamt, funct, con;
    rs = vector<bit>(ADDR_BUS_SIZE);
    rt = vector<bit>(ADDR_BUS_SIZE);
    rd = vector<bit>(ADDR_BUS_SIZE);
    op = vector<bit>(OP_SIZE);
    shamt = vector<bit>(SHAMT_SIZE);
    funct = vector<bit>(FUNCT_SIZE);
    con = vector<bit>(CONST_SIZE);

    for (int i = 0; i < ADDR_BUS_SIZE; ++i) {
        // Set the addresses
        rs[i] = instruction[i + 6];
        rt[i] = instruction[i + 11];
        rd[i] = instruction[i + 16];
    }

    for (int i = 0; i < OP_SIZE; ++i)
        // Set the op field
        op[i] = instruction[i];
    reverse(op.begin(), op.end());

    for (int i = 0; i < SHAMT_SIZE; ++i)
        // Set the shift amount field
        shamt[i] = instruction[i + 21];

    for (int i = 0; i < FUNCT_SIZE; ++i)
        // Set the funct field
        funct[i] = instruction[i + 26];
    reverse(funct.begin(), funct.end());

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
    aluControl->funct = funct;
    aluControl->aluOp0 = control->aluOp0;
    aluControl->aluOp1 = control->aluOp1;
    aluControl->process();

    // RegisterBank
    registerBank->regWrite = control->regWrite;
    registerBank->readReg1 = rs;
    registerBank->readReg2 = rt;
    registerBank->writeReg = (others->regInMux) ? rd : rt;
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
    cout << "\nRegister Bank:\n\n";

    cout << "\tInputs:\n";
    cout << "\t\tRead Register 1:\n\t\t";
    printVec(registerBank->readReg1);
    cout << "\n\t\t(" << bitVecToInt(registerBank->readReg1) << " decimal)\n";

    cout << "\n\t\tRead Register 2:\n\t\t";
    printVec(registerBank->readReg2);
    cout << "\n\t\t(" << bitVecToInt(registerBank->readReg2) << " decimal)\n";

    cout << "\n\t\tWrite Register:\n\t\t";
    printVec(registerBank->writeReg);
    cout << "\n\t\t(" << bitVecToInt(registerBank->writeReg) << " decimal)\n";
    cout << "\t\t(Write register mux = " << others->regInMux << ")\n";

    cout << "\n\t\tWrite Data:\n\t\t";
    printVec(registerBank->writeData);
    cout << "\n\t\t(" << bitVecToInt(registerBank->writeData) << " decimal)\n\n";

    cout << "\tControl Lines:\n";
    cout << "\t\tRegWrite: " << registerBank->regWrite << "\n\n";

    cout << "\tOutputs\n";
    cout << "\t\tRead Data 1:\n\t\t";
    printVec(registerBank->readData1);
    cout << "\n\t\t(" << bitVecToInt(registerBank->readData1) << " decimal)\n";

    cout << "\n\t\tRead Data 2:\n\t\t";
    printVec(registerBank->readData2);
    cout << "\n\t\t(" << bitVecToInt(registerBank->readData2) << " decimal)\n\n";
}

void Datapath::showALUData() {
    cout << "\nALU:\n\n";

    cout << "\tInputs:\n";
    cout << "\t\tInput A:\n\t\t";
    printVec(alu->inputA);
    cout << "\n\t\t(" << bitVecToInt(alu->inputA) << " decimal)\n";

    cout << "\n\t\tInput B:\n\t\t";
    printVec(alu->inputB);
    cout << "\n\t\t(" << bitVecToInt(alu->inputB) << " decimal)\n";
    cout << "\t\t(Input B mux = " << others->aluInMux << ")\n\n";

    cout << "\tControl Lines:\n";
    cout << "\t\tAInvert: " << alu->AInvert << "\n";
    cout << "\t\tBNegate: " << alu->BNegate << "\n";
    cout << "\t\tOperation: " << resOpToStr(alu->operation) << "\n\n";

    cout << "\tOutputs\n";
    cout << "\t\tZero:\n\t\t" << alu->zero << '\n';

    cout << "\n\t\tResult:\n\t\t";
    printVec(alu->result);
    cout << "\n\t\t(" << bitVecToInt(alu->result) << " decimal)\n\n";
}

void Datapath::showMainMemData() {
    cout << "\nMain Memory:\n\n";

    cout << "\tInputs:\n";
    cout << "\t\tAddress:\n\t\t";
    printVec(mem->address);
    cout << "\n\t\t(" << bitVecToInt(mem->address) << " decimal)\n";

    cout << "\n\t\tWrite Data:\n\t\t";
    printVec(mem->writeData);
    cout << "\n\t\t(" << bitVecToInt(mem->writeData) << " decimal)\n\n";

    cout << "\tControl Lines:\n";
    cout << "\t\tMemWrite: " << mem->memWrite << "\n";
    cout << "\t\tMemRead: " << mem->memRead << "\n\n";

    cout << "\tOutputs\n";
    cout << "\t\tRead Data:\n\t\t";
    printVec(mem->readData);
    cout << "\n\t\t(" << bitVecToInt(mem->readData) << " decimal)\n";
    cout << "\t\t(Memory out mux = " << others->memOutMux << ")\n\n";
}

void Datapath::showResults(unsigned int i) {
    cout << "##################################################################";
    cout << "\nInstruction " << i << "(";
    printVec(instruction);
    cout << "):\n";
    showRegData();
    showALUData();
    showMainMemData();
}
