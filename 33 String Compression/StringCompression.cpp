// https://leetcode.com/problems/string-compression/description/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char> &chars)
{
    int n = chars.size();

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        char curr = chars[i];
        int currCount = 0;
        while (i < n && chars[i] == curr)
        {
            currCount++, i++;
        }

        if (currCount == 1)
        {
            chars[idx++] = curr;
        }
        else
        {
            chars[idx++] = curr;
            for (auto &&x : to_string(currCount))
            {
                chars[idx++] = x;
            }
        }
        i--;
    }
    chars.resize(idx);
    
    return chars.size();
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << compress(chars);
    return 0;
}