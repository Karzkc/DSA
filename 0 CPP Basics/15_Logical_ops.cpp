#include <iostream>

int main() {
    using namespace std;
    // && 
    int num ;
    cin >> num ;
    
    if (num > 60 && num < 70)
    {
        std::cout << "Yess dhaddhy" << std::endl;
        
    }
    else if(num>60 || num %2){
        cout << "No dhady" << endl;
        
    }
    else if (num != 69){
        cout << "no 69" << endl;
        
    }
    
    return 0;
}