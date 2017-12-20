# ifndef alucomponents_h
# define alucomponents_h

/* Declaration of some components of the ALU. Notice that the multiplexers
meant to invert bits A or B are not present since they can be simply expressed
as boolean values, hence they are declared in alu.h */

# define bit unsigned short

class Adder {
    /* 1-Bit adder */
private:
    bit result, carryOut;
public:
    void operator () (const bit a, const bit b, const bit in);
};

class And {
    /* AND logic gate */
private:
    bit result;
public:
    void operator () (const bit a, const bit b);
};

class Or {
    /* OR logic gate*/
private:
    bit result;
public:
    void operator () (const bit a, const bit b);
};

class OverflowDetection {
    /* Overflow detection circuit */
private:
    bit overflow;
public:
    OutBits operator () (const bit a, const bit b);
};

# endif
