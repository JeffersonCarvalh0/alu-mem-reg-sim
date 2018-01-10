# include "utils.h"
# include <vector>
# include <algorithm>   // std::reverse
# include <cmath>       // pow
# include <iostream>

using namespace std;

int bitVecToInt(vector<bit> vec) {
    /* Converts a vector of bits to an integer */
    int result = 0, size = vec.size();
    reverse(vec.begin(), vec.end());

    for (int i = 0; i < size; ++i)
        result += vec[i] * pow(2, i);

    return result;
}

void printVec(const vector<bit> &vec) {
    int size = vec.size();
    for(int i = 0; i < size; ++i)
        cout << vec[i];
}

string resOpToStr(ResultOptions op) {
    switch (op) {
        case AND:
            return "00 (AND)";
        case OR:
            return "01 (OR)";
        case SUM:
            return "10 (SUM)";
        case LESS:
            return "11 (LESS)";
        default:
            return "";
    }
}
