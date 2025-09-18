#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

bool isPalindrome(string s)
{

    int i = 0, j = s.length() - 1;
    bool isp = true;

    while (i <= j)
    {
        if (!isalnum(s[i]))
        {
            i++;
            continue;
        }
        if (!isalnum(s[j]))
        {
            j--;
            continue;
        }

        if (tolower(s[i]) != tolower(s[j]))
        {
            isp = false;
            return isp;
        }

        i++;
        j--;
    }
    return isp;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);
    return 0;
}