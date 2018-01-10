# ifndef UTILS_ALU_H
# define UTILS_ALU_H

# include "defs.h"
# include <vector>
# include <string>

/* General functions used by the program. */

int bitVecToInt(std::vector<bit> vec);
void printVec(const std::vector<bit> &vec);
std::string resOpToStr(ResultOption op);

# endif /* end of include guard: UTILS_H */
