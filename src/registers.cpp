# include "registers.h"
# include "utils.h"     // bitVecToInt
# include <vector>

using namespace std;

Register::Register() {
    data = vector<bit>(WORD);
}

void Register::operator = (vector<bit> &r) {
    data = r;
}

RegisterBank::RegisterBank() {
    registers = vector<Register>(REG_NUM);
    readReg1 = readReg2 = writeReg = vector<bit>(ADDR_BUS_SIZE);
    writeData = readData1 = readData2 = vector<bit>(WORD);
}

void RegisterBank::read() {
    int reg1Addr = bitVecToInt(readReg1);
    int reg2Addr = bitVecToInt(readReg2);
    readData1 = registers[reg1Addr].data;
    readData2 = registers[reg2Addr].data;
}

void RegisterBank::write() {
    if (regWrite) {
        int regAddr = bitVecToInt(writeReg);
        registers[regAddr] = writeData;
    }
}
