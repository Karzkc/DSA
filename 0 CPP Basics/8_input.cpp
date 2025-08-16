#include <iostream>
// cout - insertion op
// cin - extraction op
int main() {
    std::string name , surname ;
    

    std::cout << "What is your name? ";
    std::cin >> name ; // using cin

    std::cout << "Enter Your surname: ";
    std::getline(std::cin>>std::ws, surname);// using getline only for string
    
    std::cout << "Your name is: " << name << std::endl;
    std::cout << "Your surname is: " <<surname << std::endl;
    
    
     
    
    return 0;
}