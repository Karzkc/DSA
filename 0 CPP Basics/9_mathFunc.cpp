#include <iostream>
#include <cmath>

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Max: "<<std::max(a,b) << std::endl;
    std::cout << "Min: "<<std::min(a,b) << std::endl;
    std::cout << "2 raised to power 3 is : "<<pow(2,3) << std::endl;
    std::cout << "Square root of 9 is : "<<sqrt(9) << std::endl;
    std::cout << "Absoulte value of minus pi is : "<<abs(-3.14) << std::endl; // for negative and decimal 
    std::cout << "Round off value of minus pi is : "<<round(-3.14) << std::endl; // for decimal only 
    std::cout << "Ceil of pi is : "<<ceil(3.14) << std::endl;  
    std::cout << "Floor of pi is : "<<floor(3.14) << std::endl; 
    
    
    return 0;
}