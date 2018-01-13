# include "datapath.h"
# include <iostream>
# include <vector>

using namespace std;

int main() {
    // Create the devices of the datapath
    RegisterBank registerBank;
    ControlUnit control;
    ALUControl aluControl;
    FullALU alu;
    MainMemory mem;

    // Create the datapath
    MinorDevices others;
    Datapath datapath(&reg, &control, &aluControl, &alu, &mem, &others);

    vector<bit> instruction = {}

    return 0;
}
