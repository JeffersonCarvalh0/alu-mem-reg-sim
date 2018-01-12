# ifndef CONTROL_UNIT
# define CONTROL_UNIT

# include "defs.h"
# include <vector>

 // Forward declarations
class ALUControl;

class ControlUnit {
    /* Main control unit. Recieves the OP field of the instruction as an input,
    and then sets the control lines in the devices along the datapath.*/
    friend class Datapath;
private:
    ALUControl *aluControl;

    // Inputs
    std::vector<bit> op;

    // Outputs
    bit regDst, aluSrc, memToReg, regWrite, memRead, memWrite, branch, aluOp1,
    aluOp0;

public:
    ControlUnit(ALUControl *aluControl);
    void process();
};

class ALUControl {
    /* Control for the ALU. It recieves an ALUOp from the ControlUnit and the
    funct field of the instruction. Then, it sets the control lines in the
    ALU. */
    friend ControlUnit;
    friend class Datapath;
private:
    // Inputs
    bit aluOp0, aluOp1;
    std::vector<bit> funct;

    // Outputs
    bit op1, op2, BNegate, AInvert;

public:
    ALUControl();
    void process();
};

# endif /* end of include guard: CONTROL_UNIT */
