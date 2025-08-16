#include <iostream>

int main() {
    using namespace std;
    // Bitwise AND example
    int a = 5, b = 7;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a & b = " << (a & b) << endl; // 5 & 7 = 5

    // Bitwise OR example
    cout << "a | b = " << (a | b) << endl; // 5 | 7 = 7

    // Bitwise XOR example
    cout << "a ^ b = " << (a ^ b) << endl; // 5 ^ 7 = 2

    // Bitwise NOT example
    cout << "~a = " << (~a) << endl; // ~5 = -6

    // Bitwise left shift
    cout << "a << 1 = " << (a << 1) << endl; // 5 << 1 = 10

    // Bitwise right shift
    cout << "b >> 1 = " << (b >> 1) << endl; // 7 >> 1 = 3
    
    
    return 0;
}