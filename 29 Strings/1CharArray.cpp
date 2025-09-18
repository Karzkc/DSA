#include <iostream>
using namespace std;

int main() {
    // 1. Basic char array declaration
    char str1[10]; // Uninitialized char array
    char str2[10] = {'h', 'e', 'l', 'l', 'o', '\0'}; // Initialize with null terminator
    char str3[] = "hello"; // Automatic null terminator added

    // 2. Null terminator ('\0') significance
    // - Marks end of string
    // - Without it, string functions won't know where to stop
    char withNull[6] = "hello"; // Automatically adds \0
    char withoutNull[5] = {'h', 'e', 'l', 'l', 'o'}; // Dangerous! No null terminator

    // 3. Different input methods
    char input1[50];
    char input2[50];
    char input3[50];

    // Method 1: cin (stops at whitespace)
    cout << "Enter string (cin): ";
    cin >> input1;

    // Clear buffer for next input
    cin.ignore();

    // Method 2: cin.getline(array, size)
    cout << "Enter string (getline with size): ";
    cin.getline(input2, 50);

    // Method 3: cin.getline(array, size, delimiter)
    cout << "Enter string (getline with delimiter '#'): ";
    cin.getline(input3, 50, '#');

    // Display results
    cout << "\nResults:" << endl;
    cout << "cin input: " << input1 << endl;
    cout << "getline input: " << input2 << endl;
    cout << "getline with delimiter: " << input3 << endl;

    // 4. Finding string length manually
    int len = 0;
    while(str2[len] != '\0') {
        len++;
    }
    cout << "Length of str2: " << len << endl;

    return 0;
}