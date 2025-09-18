#include <iostream>
#include <algorithm>

// https://leetcode.com/problems/reverse-words-in-a-string/description/
using namespace std;

string reverseWords(string s)
{
    string rev = "";
    reverse(s.begin(), s.end());
    for (int k = 0; k < s.length(); k++)
    {
        string word = "";
        while (s[k] != ' ' && k < s.length())
        {
            word += s[k++];
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0)
        {
            rev += " "+word;
        }
    }

    return rev.substr(1);
}

int main()
{
    string s = "the sky is blue";
    string result = reverseWords(s);
    cout << result;
    return 0;
}