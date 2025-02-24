#include <iostream>

int main() {
    using namespace std;
    // all std math ops used in other langs + - * / , += etc    
    int number = 10 ;
    // order - () , * / , + -
    number += 1 ;
    cout << number << endl;

    number ++ ;
    cout << number << endl;

    number -- ;
    cout << number << endl;

    number -= 1 ;
    cout << number << endl;

    number *= 1 ;
    cout << number << endl;

    number /= 1 ;
    cout << number << endl;

    double rem = number%3 ;
    cout << rem << endl;
    
    
    return 0;
}