#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4};

    // An array name ('arr') acts as a pointer to its first element.
    // Dereferencing it (*arr) gives the value of the first element, arr[0].
    cout << *arr << endl;

    // Using pointer arithmetic to access the next element.
    // *(arr + 1) is equivalent to arr[1].
    cout << *(arr + 1) << endl;

    // The address of an array is constant and cannot be reassigned.
    // Therefore, you cannot make 'arr' point to a different memory location.
    int num = 10;
    // arr = &num; // This line causes a compilation error because 'arr' is a constant pointer.
    
    return 0;
}
