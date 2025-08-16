#include <iostream>

namespace space1
{
    int x = 1;
    
} 

namespace space2
{
    int x = 2;
} 
namespace space3
{
    int y = 10;
} 

int main() {
    int x = 3;
    std::cout << x << std::endl;
    std::cout << space1::x << std::endl;
    std::cout << space2::x << std::endl;
    // :: - know as scope resolution operator
    

    //calling a space locally
    using namespace space3;
    std::cout << y << std::endl;
    
    // to save time we can call std locally , but as std contain 100s of more component use it carefully
    using namespace std;
    // by this we can directly to anything
    cout << "hello" << endl; // same as - 
    std::cout << "hello" ;
    
    // by this we can init strings also 
    string name = "kk";
    
    
    
    return 0;
}