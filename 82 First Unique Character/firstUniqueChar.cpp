// https://leetcode.com/problems/first-unique-character-in-a-string/
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> m;
    queue<int> q;

    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) == m.end())
        {
            q.push(i);
        }
        m[s[i]]++;
        while (!q.empty() && m[s[q.front()]] > 1)
        {
            q.pop();
        }
    }
    return q.empty() ? -1 : q.front();
}

int main()
{

    return 0;
}