#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{
    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
        swap(s[i++], s[j--]);
    }
}

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    for (auto &&chr : s)
    {
        cout << chr;
    }
    cout << endl;
    reverseString(s);
    for (auto &&chr : s)
    {
        cout << chr;
    }
    return 0;
}