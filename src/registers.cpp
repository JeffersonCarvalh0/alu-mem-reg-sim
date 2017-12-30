# include "registers.h"
# include <vector>

using namespace std;

Register::Register() {
    bits = vector<bit>(WORD);
}

void Register::operator = (vector<bit> &r) {
    bits = r;
}

RegisterBank::RegisterBank() {
    registers = vector<Register>(REG_NUM);
    readReg1 = readReg2 = writeReg = readData1 = readData2 = vector<bit>(WORD);
}
