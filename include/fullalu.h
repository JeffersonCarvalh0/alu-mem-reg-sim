# ifndef FULLALU_H
# define FULLALU_H

# include "alu.h"
# include <vector>

class ControlUnit; // Forward declaration

class FullALU {
    /* Represents a full ALU with 32 bits. */
    friend class ControlUnit;

public: // Will be made private when the Control Unit is done
    std::vector<ALU*> aluArr;

    // Control lines
    bool AInvert, BNegate;
    ResultOptions operation;

    // Input
    std::vector<bit> inputA, inputB;

    // Output
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
