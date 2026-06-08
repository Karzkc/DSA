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
int lcm(int a, int b)
{
    // lcm(a,b) = a*b/gcd(a,b)
    int lcm = (a * b) / gcd(a, b);
    return lcm;
}
int main()
{
    int res = lcm(2, 7);
    cout << res;
    return 0;
}