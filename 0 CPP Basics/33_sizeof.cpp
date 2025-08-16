#include <iostream>

int main() {
    using namespace std;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;

    int arr[10];
    cout << "Size of arr (int[10]): " << sizeof(arr) << " bytes" << endl;
    cout << "Number of elements in arr: " << sizeof(arr) / sizeof(arr[0]) << endl;

    struct MyStruct {
        int a;
        double b;
        char c;
    };
    cout << "Size of MyStruct: " << sizeof(MyStruct) << " bytes" << endl;

    int* ptr = arr;
    cout << "Size of pointer to int: " << sizeof(ptr) << " bytes" << endl;

    cout << "Size of literal 3.14: " << sizeof(3.14) << " bytes" << endl;
    cout << "Size of expression (a + 1): " << sizeof(arr[0] + 1) << " bytes" << endl;
    return 0;
}