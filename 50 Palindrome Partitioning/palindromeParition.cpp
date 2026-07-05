// https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool checkPalindrome(const string &currStr)
{
    int s = 0, e = (int)currStr.size() - 1;
    while (s < e)
    {
        if (currStr[s++] != currStr[e--])
            return false;
    }
    return true;
}
void getPartition(vector<vector<string>> &ans, string s,
                  vector<string> &curr)
{
    int n = s.size();
    if (n == 0)
    {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        string currStr = s.substr(0, i + 1);
        if (checkPalindrome(currStr))
        {
            curr.push_back(currStr);
            getPartition(ans, s.substr(i + 1), curr);
            curr.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> curr;

    getPartition(ans, s, curr);
    return ans;
}

int main()
{

    return 0;
}