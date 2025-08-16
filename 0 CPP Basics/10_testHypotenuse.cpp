#include <iostream>
#include <cmath>

int main()
{

    double base;
    double perpendicular;
    double hypotenuse;

    std::cout << "Enter value of base of triangle : ";
    std::cin >> base;

    std::cout << "Enter value of perpendicular of triangle : ";
    std::cin >> perpendicular;

    hypotenuse = sqrt(pow(perpendicular,2) + pow(base,2) );
    std::cout << "Hypotenuse of triangle with base " << base
              << " and perpendicular " << perpendicular
              << " is: " << hypotenuse << " units" << std::endl;

    return 0;
}