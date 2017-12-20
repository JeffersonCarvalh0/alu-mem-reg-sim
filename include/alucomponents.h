# ifndef alucomponents_h
# define alucomponents_h

/* Declaration of some components of the ALU. Notice that the multiplexers
meant to invert bits A or B are not present since they can be simply expressed
as boolean values, hence they are declared in alu.h */

# define bit unsigned short

// Forward declarations
class ALU;
class MSALU;

class Adder {
    /* 1-Bit adder */
    friend class ALU;
    friend class MSALU;
private:
    bit result, carryOut;
public:
    void operator () (const bit a, const bit b, const bit in);
};

class And {
    /* AND logic gate */
    friend class ALU;
    friend class MSALU;
private:
    bit result;
public:
    void operator () (const bit a, const bit b);
};

class Or {
    /* OR logic gate*/
    friend class ALU;
    friend class MSALU;
private:
    bit result;
public:
    void operator () (const bit a, const bit b);
};

class OverflowDetection {
    /* Overflow detection circuit */
    friend class ALU;
    friend class MSALU;
private:
    bit result;
public:
    void operator () (const bit a, const bit b);
};

# endif
