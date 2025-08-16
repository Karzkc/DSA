#include <iostream>

int main() {
    using namespace std;
    int age;
    cout << "Enter Your age:- " << endl;
    cin >>age ;
    if (age>=18)
    {
        cout << "You are eligible" << endl;
        
    }
    else if (age<18)
    {
        cout << "You are not eligible" << endl;
        
    }
    else
    {
        cout << "Your age is not valid" << endl;
        
    }
    
    return 0;
}