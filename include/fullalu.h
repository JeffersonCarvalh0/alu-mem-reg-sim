# ifndef FULLALU_H
# define FULLALU_H

# include "alu.h"
# include <vector>

/* Full ALU class. It takes a bunch of ALUs together and makes operations
with multiple bits. */

class FullALU {
    /* Represents a full ALU with 32 bits. */
    friend class ControlUnit;
    friend class Datapath;

private:
    std::vector<ALU*> aluArr;

    // Control lines
    bool AInvert, BNegate;
    ResultOptions operation;

    // Inputs
    std::vector<bit> inputA, inputB;

    // Outputs
    bool zero, overflow;
    std::vector<bit> result;

private:
    // Set the bits in the current ALU
    inline void setBits(const int i, const bit lastCarryOut) const;

public:
    FullALU();
    void process();
};

# endif
