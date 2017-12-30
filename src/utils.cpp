# include "utils.h"
# include <vector>
# include <algorithm>   // std::reverse
# include <cmath>       // pow

using namespace std;

int bitVecToInt(vector<bit> vec) {
    /* Converts a vector of bits to an integer */
    int result = 0, size = vec.size();
    reverse(vec.begin(), vec.end());

    for (int i = 0; i < size; ++i)
        result += vec[i] * pow(2, i);

    return result;
}
