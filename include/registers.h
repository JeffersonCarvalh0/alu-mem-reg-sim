# ifndef REGISTERS_H
# define REGISTERS_H

# include "defs.h"
# include <vector>

/* In this file, the processor's registers and its register bank are defined. */

# define REG_ADDR_LINES 5
# define REG_NUM 32

class Register {
    /* Represents a single register. */
    friend class RegisterBank;

private:
    std::vector<bit> bits;

public:
    Register();
    void operator = (std::vector<bit> &r);
};

class RegisterBank {
    /* Represents the bank of registers in the datapath. */
    friend class ControlUnit;

private: // Will be made public when control unit is done
    bool regWrite;

private:
    std::vector<Register> registers;

    // Inputs
    std::vector<bit> readReg1, readReg2, writeReg;

    // Outputs
    std::vector<bit> readData1, readData2;

public:
    RegisterBank();
};

# endif /* end of include guard: REGISTERS_H */
