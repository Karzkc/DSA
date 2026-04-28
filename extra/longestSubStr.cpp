#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    // s = "abcabcbb"
    int maxNum = 1;
    int length = 0;
    string sub;
    if (!s.empty())
    {
        sub.push_back(s[0]);
    }
    for (int i = 1; i < s.length(); i++)
    {
        if (sub.find(s[i])==string::npos)
        {
            sub.push_back(s[i]);
            cout << sub << endl;
            
            length++;
            maxNum = max(maxNum, length);
        }
        else
        {
            sub.clear();
            sub.push_back(s[i]);
            length = 0;
        }
    }
    return maxNum;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    
}
