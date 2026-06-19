#include <iostream>
using namespace std;

int rec(int num)
{
    if (num == 1)
    {
        return num;
    }
    

    return rec(num--);
}
int main()
{
    
    cout << rec(8);
    return 0;
}