# ifndef UTILS_ALU_H
# define UTILS_ALU_H

# include "defs.h"
# include <vector>
# include <string>

/* General functions used by the program. */

unsigned int bitVecToInt(std::vector<bit> vec);
void printVec(const std::vector<bit> &vec);
std::string resOpToStr(ResultOptions op);
ResultOptions bitsToResOp(const bit op1, const bit op2);

# endif /* end of include guard: UTILS_H */
