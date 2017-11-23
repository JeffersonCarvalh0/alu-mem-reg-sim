# ifndef alucomponents_h
# define alucomponents_h

/* Declaration of some components of the ALU. Notice that the multiplexers
meant to invert bits A or B are not present since they can be simply expressed
as boolean values, hence they are declared in alu.h */

// Forward declarations
struct EntryBits;
struct OutBits;

class AluComponent {
public:
    virtual OutBits makeOperation(const EntryBits &in) const = 0;
};

class Adder : public AluComponent {
    /* 1-Bit adder */
public:
    virtual OutBits makeOperation(const EntryBits &in) const override;
};

class And : public AluComponent {
    /* AND logic gate */
public:
    virtual OutBits makeOperation(const EntryBits &in) const override;
};

class Or : public AluComponent {
    /* OR logic gate OR */
public:
    virtual OutBits makeOperation(const EntryBits &in) const override;
};

# endif
