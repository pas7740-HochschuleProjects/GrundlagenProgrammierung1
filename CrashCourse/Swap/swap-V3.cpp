//  Real Call-by-Reference in C++
//  Function swap() works as expected.
//

//
// Build via:
// mkdir -p bin; g++ -o bin/swap-V3 swap-V3.cpp

#include <iostream>
#include <iomanip>
using namespace std;

// References in C++ are alias names
// We operate on the variables of the caller!
void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int i1=1;
    int i2=2;

    cout << "Before swap" << endl;
    cout << "i1: " << i1 << endl;
    cout << "i2: " << i2 << endl;

    swap(i1,i2);

    cout << "After swap" << endl;
    cout << "i1: " << i1 << endl;
    cout << "i2: " << i2 << endl;

    return 0;
}

