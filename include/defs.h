# ifndef DEFS_H
# define DEFS_H

/* File used for defines, enums and global constants */

# define bit bool // Data type used to represente bits
# define WORD 32 // Word size used in the simulator

// Enums
enum ResultOptions {
    // 1-bit ALU's mux to select its output
    AND, OR, SUM, LESS
};

# endif /* end of include guard: DEFS_H */
