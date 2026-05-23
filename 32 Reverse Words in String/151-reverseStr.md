https://leetcode.com/problems/reverse-words-in-a-string/description/

# Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = " hello world "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Constraints:
    1 <= s.length <= 104
    s contains English letters (upper-case and lower-case), digits, and spaces ' '.
    There is at least one word in s.


## Intuition
We need to reverse the order of words in the string while:
- removing extra spaces
- keeping only one space between words

👉 Reverse the whole string first, then reverse each individual word.

---

## Key Insight
- Reversing whole string reverses word order
- Each word itself also gets reversed
- Reverse every word again to restore proper spelling

---

## Approach
1. Reverse entire string
2. Traverse string and extract words
3. Reverse each word individually
4. Append valid words into answer string
5. Avoid extra spaces

---

## Complexity
- **Time:** `O(n)`
- **Space:** `O(n)`

---

## Code
```cpp
string reverseWords(string s)
{
    string rev = "";

    reverse(s.begin(), s.end());

    for (int k = 0; k < s.length(); k++)
    {
        string word = "";

        while (k < s.length() && s[k] != ' ')
        {
            word += s[k++];
        }

        reverse(word.begin(), word.end());

        if (!word.empty())
        {
            if (!rev.empty())
                rev += ' ';

            rev += word;
        }
    }

    return rev;
}
````



