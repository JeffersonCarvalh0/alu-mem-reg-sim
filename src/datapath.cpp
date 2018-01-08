# include "datapath.h"
# include "fullalu.h"
# include "mainmemory.h"
# include "registers.h"
# include <vector>

using namespace std;

vector<bit> MinorDevices::signExtend(const vector<bit> &in) {
    vector<bit> out(WORD);

    for (int i = CONST_SIZE; i < WORD; ++i)
        out[i] = in[i];

    for (int i = 0; i < CONST_SIZE; ++i)
        out[i] = 0;

    return out;
}

Datapath::Datapath(RegisterBank *reg, ControlUnit *control, FullALU *alu,
    MainMemory *mem, MinorDevices *others) : registerBank(reg),
    controlUnit(control), alu(alu), mem(mem), others(others) {};

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

    // RegisterBank
    registerBank->readReg1 = rs;
    registerBank->readReg2 = rt;
    registerBank->writeReg = (others->regInMux) ? shamt : rt;
    registerBank->read();

    // ALU
    alu->inputA = registerBank->readData1;
    alu->inputB = (others->aluInMux) ? others->signExtend(con) : registerBank->readData2;
    alu->process();

    // Main memory
    mem->address = alu->result;
    mem->writeData = registerBank->readData2;
    mem->process();

    // RegisterBank again
    registerBank->writeData = (others->memOutMux) ? mem->readData : alu->result;
    registerBank->write();
}
