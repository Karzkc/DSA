#include <iostream>
// https://leetcode.com/problems/permutation-in-string/description/
using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s1.length() > s2.length()) return false;
    
    int count1[26] = {0};
    int count2[26] = {0};
    
    for (int i = 0; i < s1.length(); i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }
    
    for (int i = 0; i <= s2.length() - s1.length(); i++) {
        bool match = true;
        for (int j = 0; j < 26; j++) {
            if (count1[j] != count2[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
        
        if (i < s2.length() - s1.length()) {
            count2[s2[i] - 'a']--;
            count2[s2[i + s1.length()] - 'a']++;
        }
    }
    return false;
}

int main()
{
    string s1 = "ab", s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);
    return 0;
}