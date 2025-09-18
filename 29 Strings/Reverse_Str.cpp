#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s = "hello";
    for (auto &&chr : s)
    {
        cout << chr;
    }
    cout << endl;
    reverse(s.begin(), s.end());
    for (auto &&chr : s)
    {
        cout << chr;
    }
    return 0;
}