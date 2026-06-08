#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    // euclid's theorem
    int a = 25;
    int b = 20;
    int res = gcd(a,b)
    cout << res;
    return 0;
}