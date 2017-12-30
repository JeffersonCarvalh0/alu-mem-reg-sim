# ifndef DEFS_H
# define DEFS_H

/* File used for defines, enums and global constants */

# define WORD 32 // Word size used in the simulator

typedef bool bit; // Data type used to represente bits

// Enums
enum ResultOptions {
    // 1-bit ALU's mux to select its output
    AND, OR, SUM, LESS
};

# endif /* end of include guard: DEFS_H */
