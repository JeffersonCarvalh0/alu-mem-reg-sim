# include "fullalu.h"
# include <iostream>
# include <vector>

using namespace std;

int main() {
    FullALU alu;

    vector<bit> a = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 1
    };

    vector<bit> b = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 1, 0
    };

    // 5 - 5
    alu.AInvert = false;
    alu.BNegate = false;
    alu.operation = OR;
    alu.inputA = a;
    alu.inputB = b;
    alu.process();

    cout << "Overflow: " << alu.overflow << '\n';
    cout << "Result: \n";
    for (auto &e : alu.result)
        cout << e;
    cout << endl;

    return 0;
}
