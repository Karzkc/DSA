#include <iostream>
using namespace std;

int main() {
    // Pointer arithmetic is scaled by the size of the data type.
    // For an 'int', which is typically 4 bytes, adding 1 to a pointer
    // increases its memory address by 4, moving it to the next integer.
    
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr; // ptr points to the first element, arr[0]

    cout << "--- Pointer Arithmetic ---" << endl;
    cout << "Size of one integer block: " << sizeof(int) << " bytes" << endl;
    cout << "Initial pointer value (address of arr[0]): " << ptr << endl;
    cout << "Initial value at pointer (*ptr): " << *ptr << endl;
    cout << "\n";

    // --- 1. Increment (++) ---
    // Moves the pointer forward by one block (sizeof(int) bytes).
    cout << "--- 1. Increment (ptr++) ---" << endl;
    ptr++;
    cout << "After ptr++, pointer is at address: " << ptr << endl;
    cout << "Value at new address (*ptr): " << *ptr << endl; // Now points to 20
    cout << "\n";

    // --- 2. Decrement (--) ---
    // Moves the pointer backward by one block (sizeof(int) bytes).
    cout << "--- 2. Decrement (ptr--) ---" << endl;
    ptr--;
    cout << "After ptr--, pointer is back at address: " << ptr << endl;
    cout << "Value at new address (*ptr): " << *ptr << endl; // Now points back to 10
    cout << "\n";

    // --- 3. Addition (+) ---
    // Calculates a new address by adding an offset of N blocks.
    // The actual address change is N * sizeof(int).
    cout << "--- 3. Addition (ptr + 3) ---" << endl;
    int* ptr_add = ptr + 3; // Points to arr[3]
    cout << "Address of (ptr + 3): " << ptr_add << endl;
    cout << "Value at that address (*(ptr + 3)): " << *ptr_add << endl; // Value is 40
    cout << "\n";

    // --- 4. Subtraction (-) ---
    // Calculates a new address by subtracting an offset of N blocks.
    cout << "--- 4. Subtraction (ptr_add - 2) ---" << endl;
    int* ptr_sub = ptr_add - 2; // Points to arr[1]
    cout << "Address of (ptr_add - 2): " << ptr_sub << endl;
    cout << "Value at that address (*(ptr_add - 2)): " << *ptr_sub << endl; // Value is 20
    cout << "\n";

    // --- 5. Subtracting two pointers ---
    // Calculates the number of elements (blocks) between two pointers.
    // The result is (address2 - address1) / sizeof(int).
    cout << "--- 5. Subtracting two pointers (ptr_add - ptr) ---" << endl;
    cout << "Elements between ptr_add and ptr: " << ptr_add - ptr << endl; // Result is 3
    cout << "\n";

    // --- 6. Comparison (==, <, >) ---
    // Compares the memory addresses stored in the pointers.
    cout << "--- 6. Comparison ---" << endl;
    int* ptr2 = &arr[3];
    cout << "Is ptr_add == ptr2? " << (ptr_add == ptr2 ? "True" : "False") << endl;
    cout << "Is ptr < ptr2? " << (ptr < ptr2 ? "True" : "False") << endl;
    
    return 0;
}
