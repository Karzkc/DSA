#include <iostream>

int main() {
    int x = 10;
    x = 45; // reassign
    float y = 3.14 ; 
    y = 4.14;
    std::cout << x <<" " <<y <<std::endl;

    //but if constant no reassignment capital only
    const double PI = 3.14;
    // pi = 4.11 ; // wont work
    std::cout << PI << std::endl;
    
    
    return 0;
}