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

    while (cin << instruction) {
        datapath.setInstruction(instruction);
        datapath.processInstruction();
        datapath.showRegData();
        datapath.showALUData();
        datapath.showMainMemData();
    }

    return 0;
}
