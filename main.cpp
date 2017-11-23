# include "adder.h"
# include <iostream>

using namespace std;

int main() {
    Adder adder1, adder2;
    EntryBits in;
    OutBits out;

    in.carryIn = 1;
    in.bitA = 1;
    in.bitB = 1;

    adder1.setInBits(in);
    out = adder1.makeOperation();
    cout << "Resultado: " << out.result << '\n';
    cout << "Vai um: " << out.carryOut << endl;

    cout << "Resultado: " << out.result << '\n';
    cout << "Vai um: " << out.carryOut << endl;
}
