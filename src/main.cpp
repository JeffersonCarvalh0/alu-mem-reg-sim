# include "datapath.h"
# include <iostream>
# include <string>

using namespace std;

int main() {
    // Create the devices of the datapath
    RegisterBank *registerBank = new RegisterBank();
    ControlUnit *control = new ControlUnit();
    ALUControl *aluControl = new ALUControl();
    FullALU *alu = new FullALU();
    MainMemory *mem = new MainMemory();

    // Create the datapath
    MinorDevices *others = new MinorDevices();
    Datapath datapath(registerBank, control, aluControl, alu, mem, others);

    string instruction;

    vector<bit> maxIntReg = {1, 0, 0, 0, 0};

    datapath.setMaxInt(maxIntReg);

    unsigned int i = 1;
    while (cin >> instruction) {
        datapath.setInstruction(instruction);
        datapath.processInstruction();
        datapath.showResults(i++);
    }

    return 0;
}
