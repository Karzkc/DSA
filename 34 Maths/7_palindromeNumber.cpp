#include <iostream>
using namespace std;

long long reverse(long long n)
{
    long long rev = 0;
    while (n != 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

bool palindrome(int x)
{
    if (x < 0)
        return false;
    return x == reverse(x);
}

int main()
{
    long long n;
    cout << "Enter number: ";
    if (!(cin >> n)) return 0;
    bool isPalindrome = palindrome(n);
    cout << boolalpha << isPalindrome << "\n";
    return 0;
}