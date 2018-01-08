# ifndef DEFS_H
# define DEFS_H

/* File used for defines, enums and global constants */

# define WORD 32 // Word size used in the simulator
# define ADDR_BUS_SIZE 5 // Size of an address bus
# define CONST_SIZE 16 // Size of a constant in an instruction
# define OP_SIZE 6 // Size of the op field in the instruction
# define SHAMT_SIZE 5 // Size of the shamt field in the instruction
# define FUNCT_SIZE 6 // Size of the funct field in the instruction

typedef bool bit; // Data type used to represente bits

// Enums
enum ResultOptions {
    // 1-bit ALU's mux to select its output
    AND, OR, SUM, LESS
};

# endif /* end of include guard: DEFS_H */
