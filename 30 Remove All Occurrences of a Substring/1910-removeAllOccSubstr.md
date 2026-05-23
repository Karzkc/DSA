https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

# Remove All Occurrences of a Substring

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.
A substring is a contiguous sequence of characters in a string.

Example 1:
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:

- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
  Now s has no occurrences of "abc".

Example 2:
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:

- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
  Now s has no occurrences of "xy".

## Intuition

We need to repeatedly remove a substring `part` from string `s` until it no longer exists.

👉 Each time we find `part`, we erase it and continue.

---

## Key Insight

- Use `find()` to locate substring
- Use `erase()` to remove it
- Repeat until `part` is no longer found

---

## Approach

1. Loop while substring exists:
   - Use `s.find(part)`
   - If found → erase it using `s.erase()`

2. Stop when `find()` returns `string::npos`

---

## Complexity

- **Time:** `O(n²)` (due to repeated erase and shifting)
- **Space:** `O(1)`

---

## Code

```cpp
string removeOccurrences(string s, string part) {
    while (s.find(part) != string::npos) {
        s.erase(s.find(part), part.length());
    }
    return s;
}
```
