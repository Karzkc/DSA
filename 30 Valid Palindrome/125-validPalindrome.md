https://leetcode.com/problems/valid-palindrome/description/

# Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


## Intuition

We need to check if a string is a palindrome while:

- Ignoring non-alphanumeric characters
- Ignoring case differences

👉 Use two pointers from both ends and compare valid characters.

---

## Key Insight

- Skip characters that are not letters or digits
- Compare characters in lowercase form
- Move inward until pointers meet

---

## Approach

1. Initialize two pointers:
   - `i = 0` (start)
   - `j = n - 1` (end)

2. While `i <= j`:
   - If `s[i]` is not alphanumeric → `i++`
   - If `s[j]` is not alphanumeric → `j--`
   - Else:
     - Compare `tolower(s[i])` and `tolower(s[j])`
     - If not equal → return `false`
     - Else move both pointers

3. If loop completes → return `true`

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

---

## Code

```cpp
bool isPalindrome(const string& s) {
    int i = 0;
    int j = s.length() - 1;

    while(i <= j){
        if(!isalnum(s[i])){
            i++;
            continue; // It skips the rest of the loop and goes to next iteration.
        }
        if(!isalnum(s[j])){
            j--;
            continue; // It skips the rest of the loop and goes to next iteration.
        }
        if(tolower(s[i]) != tolower(s[j])){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

```
