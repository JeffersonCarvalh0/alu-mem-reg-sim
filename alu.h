# ifndef alu_h
# define alu_h

# include "alucomponents.h"

/* Declaration of an 1-Bit ALU. It consists of an full adder, an AND and an OR
gates, all defined at alucomponents.h. It also has multiplexers to deny both
bits, implemented using boolean variables. */

struct EntryBits {
    /* Bit field that represents the entry bits of an ALU */
    unsigned carryIn : 1;
    unsigned bitA : 1;
    unsigned bitB : 1;
    unsigned less : 1;

    void operator = (EntryBits &in);
};

struct OutBits {
    /* Bit field that represents the output bits of an ALU */
    unsigned result : 1;
    unsigned carryOut : 1;
    unsigned set : 1;
};

class ALU {
public:
    // Multiplexers
    bool AInvert;
    bool BInvert;

private:
    // Bits
    EntryBits in;
    OutBits out;

    // Other components
    Adder adder;
    And andGate;
    Or orGate;

public:
    void setInBits(const EntryBits &in);
    OutBits add();
    OutBits andOp();
    OutBits orOp();

private:
    void muxSelect() const;
};

# endif
