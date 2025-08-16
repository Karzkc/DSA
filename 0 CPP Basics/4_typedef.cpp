#include <iostream>
//typedef are like macro in c
// typedef std::string string_t; 
// for more efficiency we should use using 
using string_t = std::string ; 

int main() {
    
    std::string hello = "Hello"; // instead of this
    string_t world = "World";
    std::cout << hello << "," << world << std::endl;
    
    return 0;
}