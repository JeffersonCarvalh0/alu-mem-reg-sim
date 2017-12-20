# ifndef alu_h
# define alu_h

# include "alucomponents.h"

/* Declaration of an 1-Bit ALU. It consists of an full adder, an AND and an OR
gates, all defined at alucomponents.h. It also has multiplexers to deny both
bits, implemented using boolean variables. */

class FullALU; // Forward declaration

enum ResultOptions {
    /* Enum for the result selector */
    AND, OR, SUM, LESS
};

class ALU {
    friend class FullALU; // The FullALU class will set ALU's attributes
protected:
    // 2x1 Multiplexers
    bool AInvert;
    bool BInvert;

    // Bits
    bit carryIn, a, b, less;    // Input
    bit result, carryOut;       // Output

    // Other components
    Adder adder;
    And andGate;
    Or orGate;

public:
    void process(const ResultOptions result);

private:
    void muxSelect();
};

class MSALU : public ALU {
    /* ALU for the most significant bit. It has everything an ordinary ALU
    has, plus two more output bits(set and overflow) and, of course, the
    overflow detection circuit. */
    friend class FullALU;
private:
    // Bits
    bit set, overflow;  // Output

    // Other components
    OverflowDetection ov;

public:
    void process(const ResultOptions result);
};

# endif
