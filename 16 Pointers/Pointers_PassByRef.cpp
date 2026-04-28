#include <iostream>

using namespace std;

// Method 1: Using a pointer to modify the original value.
// The function receives the memory address of the variable.
void changeValueWithPointer(int* valuePtr) {
    // Dereference the pointer to access and change the original value.
    *valuePtr = 250; 
}

// Method 2: Using a C++ reference to modify the original value.
// A reference is an alias (another name) for an existing variable.
// Changes made to the reference directly affect the original variable.
void changeValueWithReference(int& valueRef) {
    // No special syntax is needed; it works like a regular variable.
    valueRef = 450;
}

int main() {
    // --- 1. Pass by Reference with Pointers ---
    cout << "--- 1. Pass by Reference with Pointers ---" << endl;
    int number1 = 50;
    cout << "Original value: " << number1 << endl;
    
    // Pass the memory address of 'number1' to the function.
    changeValueWithPointer(&number1);
    
    cout << "Value after function call: " << number1 << endl;
    cout << "\n";

    // --- 2. Pass by Reference with C++ References (&) ---
    cout << "--- 2. Pass by Reference with C++ References (&) ---" << endl;
    int number2 = 150;
    cout << "Original value: " << number2 << endl;

    // Pass the variable directly. The function receives it as a reference.
    // This syntax is cleaner and often safer than using pointers.
    changeValueWithReference(number2);

    cout << "Value after function call: " << number2 << endl;

    return 0;
}
