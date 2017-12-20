# ifndef FULLALU_H
# define FULLALU_H

# include "alu.h"
# include <vector>

# define BITS 32

class FullALU {
    /* Represents a full ALU with 32 bits. */
private:
    std::vector<MSALU*> aluArr;

    // Control lines
    bool AInvert, BNegate;
    ResultOptions operation;

    // Input
    std::vector<bit> inputA, inputB;

    // Output
    bool zero, overflow;
    std::vector<bit> result;

    // Set the bits in the current ALU
    inline void setBits(const int i, const bit lastCarryOut) const;

public:
    FullALU();
    void process();
};

# endif
