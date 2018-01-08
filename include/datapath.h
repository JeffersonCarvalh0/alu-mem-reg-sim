# ifndef DATAPATH_H
# define DATAPATH_H

# include "defs.h"
# include <vector>

/* Classes that represents the connections between the componnents in the ALU
and some other minor devices. It is responsible for taking the outputs from one
device and send them as inputs to other devices in the datapath. */

// Forward declarations
class RegisterBank;
class ControlUnit;
class FullALU;
class MainMemory;

class MinorDevices {
    /* Other minor devices in the datapath */
    friend ControlUnit;
    friend class Datapath;
private:
    bool regInMux, regOutMux, aluInMux, memOutMux;

public:
    std::vector<bit> signExtend(const std::vector<bit> &in);
};

class Datapath {
private:
    std::vector<bit> instruction;

private: // Pointers to the devices in the datapath
    RegisterBank *registerBank;
    ControlUnit *controlUnit;
    FullALU *alu;
    MainMemory *mem;
    MinorDevices *others;

public:
    Datapath(RegisterBank *reg, ControlUnit *control, FullALU *alu,
        MainMemory *mem, MinorDevices *others);
    void getInstruction(const std::vector<bit> &instruction);
    void processInstruction();
};

# endif /* end of include guard: DATAPATH_H */
