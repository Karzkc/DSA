#include <iostream>
using namespace std;

int main() {
    // Data type modifiers and their sizes (in bits):

    // short int: typically 16 bits
    // unsigned short int: typically 16 bits
    // long int: typically 32 or 64 bits (platform dependent, usually 32 bits on most systems)
    // unsigned long int: typically 32 or 64 bits
    // long long int: typically 64 bits
    
    // 1. short int
    short int a = 32767;
    cout << "short int a: " << a << endl;

    // 2. unsigned short int
    unsigned short int b = 65535;
    cout << "unsigned short int b: " << b << endl;

    // 3. long int
    long int c = 2147483647;
    cout << "long int c: " << c << endl;

    // 4. unsigned long int
    unsigned long int d = 4294967295;
    cout << "unsigned long int d: " << d << endl;

    // 5. long long int
    long long int e = 9223372036854775807;
    cout << "long long int e: " << e << endl;

    return 0;
}