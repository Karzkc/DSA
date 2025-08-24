#include <iostream>

int main() {
    // Use the standard namespace for cout and endl
    using namespace std;

    // --- 1. Memory Address (&) ---
    // Every variable is stored at a specific location in memory.
    // The ampersand (&) operator gives you the memory address of a variable.
    cout << "--- 1. Memory Address ---" << endl;
    int num = 10;
    cout << "The value of 'num' is: " << num << endl;
    cout << "The memory address of 'num' is: " << &num << endl;
    cout << "\n"; // Add a newline for better readability

    // --- 2. Pointers (*) ---
    // A pointer is a special variable that stores a memory address.
    // 'ptr' is a pointer to an integer (int*).
    // It is initialized to hold the memory address of 'num2'.
    cout << "--- 2. Pointers ---" << endl;
    int num2 = 69;
    int* ptr = &num2;
    cout << "The value of 'num2' is: " << num2 << endl;
    cout << "The memory address of 'num2' is: " << &num2 << endl;
    cout << "The pointer 'ptr' stores the address: " << ptr << endl;
    cout << "The memory address of the pointer 'ptr' itself is: " << &ptr << endl;
    cout << "\n";

    // --- 3. Pointer to Pointer (**) ---
    // You can also have a pointer that stores the address of another pointer.
    // 'ptr2' is a pointer to a pointer to an integer (int**).
    // It is initialized to hold the memory address of 'ptr'.
    cout << "--- 3. Pointer to Pointer ---" << endl;
    int** ptr2 = &ptr;
    cout << "The pointer 'ptr' holds the address: " << ptr << endl;
    cout << "The pointer 'ptr2' stores the address of 'ptr': " << ptr2 << endl;
    cout << "\n";

    // --- 4. Dereferencing (*) ---
    // The dereference operator (*) retrieves the value stored at the memory address a pointer is holding.
    cout << "--- 4. Dereferencing ---" << endl;
    cout << "Dereferencing &num2 (*(&num2)): " << *(&num2) << endl; // Gets the value of num2
    cout << "Dereferencing ptr (*ptr): " << *ptr << endl;           // Gets the value of num2
    cout << "Dereferencing ptr2 (*ptr2): " << *ptr2 << endl;         // Gets the value of ptr (which is the address of num2)
    
    // Double dereferencing gets the value from the final address.
    cout << "Double dereferencing ptr2 (**ptr2): " << **ptr2 << endl; // Gets the value of num2
    cout << "\n";

    // --- 5. NULL Pointer ---
    // A NULL pointer is a pointer that does not point to any valid memory address.
    // It's good practice to initialize pointers to NULL if they aren't pointing to anything yet.
    cout << "--- 5. NULL Pointer ---" << endl;
    int* nptr = NULL; // or nullptr in modern C++
    cout << "The value of a NULL pointer is: " << nptr << endl;
    
    // Attempting to dereference a NULL pointer will cause a runtime error (segmentation fault)
    // because it's not pointing to a valid memory location.
    // The following line is commented out to prevent the program from crashing.
    // cout << *nptr << endl; 
    cout << "Attempting to dereference a NULL pointer causes a crash!" << endl;

    return 0;
}
