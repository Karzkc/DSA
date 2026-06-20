#include <iostream>
using namespace std;
// https://leetcode.com/problems/fibonacci-number/
int fibo(int num)
{
    if (num == 0 ||num == 1)
    {
        return num;
    }

    return fibo(num - 1) + fibo(num - 2);
}
int main()
{
    cout << fibo(5);
    return 0;
}