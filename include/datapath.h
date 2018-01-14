# ifndef DATAPATH_H
# define DATAPATH_H

# include "datapath.h"
# include "controlunit.h"
# include "fullalu.h"
# include "mainmemory.h"
# include "registers.h"
# include "utils.h"
# include "defs.h"
# include <vector>
# include <string>

/* Classes that represents the connections between the componnents in the ALU
and some other minor devices. It is responsible for taking the outputs from one
device and send them as inputs to other devices in the datapath. */

class MinorDevices {
    /* Other minor devices in the datapath */
    friend class Datapath;
private:
    bool regInMux, aluInMux, memOutMux;

public:
    std::vector<bit> signExtend(const std::vector<bit> &in);
};

class Datapath {
private:
    std::vector<bit> instruction;

private: // Pointers to the devices in the datapath
    RegisterBank *registerBank;
    ControlUnit *control;
    ALUControl *aluControl;
    FullALU *alu;
    MainMemory *mem;
    MinorDevices *others;

public:
    Datapath(RegisterBank *reg, ControlUnit *controlUnit, ALUControl *aluControl,
         FullALU *alu, MainMemory *mem, MinorDevices *others);
    void setInstruction(const std::vector<bit> &instruction);
    void setInstruction(const std::string &instruction);
    void processInstruction();
    void showRegData();
    void showALUData();
    void showMainMemData();
    void showResults(unsigned int i);
};

# endif /* end of include guard: DATAPATH_H */
