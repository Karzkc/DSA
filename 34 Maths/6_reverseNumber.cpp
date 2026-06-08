#include <iostream>
using namespace std;
int reverseNum(int n)
{
    if (n > INT_MAX / 10 && n < INT_MIN / 10)
    {
        return 0;
    }

    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}
int main()
{
    int res = reverseNum(-123404);
    cout << res;
    return 0;
}