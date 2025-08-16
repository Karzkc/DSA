#include <iostream>

int main()
{
    // using namespace std;
    int quarter;
    std::cout << "Enter Your quarter:- " << std::endl;
    std::cin >> quarter;

    switch (quarter)
    {
    case 1:
        std::cout << "Your quarter is january-march" << std::endl;
        break;
    case 2:
        std::cout << "Your quarter is april-june" << std::endl;
        break;
    case 3:
        std::cout << "Your quarter is july-September" << std::endl;
        break;
    case 4:
        std::cout << "Your quarter is october-december" << std::endl;
        break;

    default:
        std::cout << "Not verified" << std::endl;
        
        break;
    }
    return 0;
}