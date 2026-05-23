https://leetcode.com/problems/permutation-in-string/description/

# Permutation in String

Given two strings s1 and s2, return true if s2 contains a of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.


## Intuition
We need to check whether any permutation of `s1` exists as a substring in `s2`.

👉 Instead of generating all permutations, we compare character frequencies using a sliding window.

---

## Key Insight
- Two strings are permutations if:
```text
  Their character frequencies are same
```

* Maintain a window of size `s1.length()` on `s2`
* Compare frequency arrays

---

## Approach

1. If `s1.length() > s2.length()` → return `false`

2. Create two frequency arrays of size 26:

   * `f1` → frequency of `s1`
   * `f2` → frequency of current window in `s2`

3. Fill both arrays for first window

4. If frequencies match → return `true`

5. Slide window across `s2`:

   * Add new character
   * Remove old character
   * Compare frequencies

6. If no match found → return `false`

---

## Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

---

## Code

```cpp
bool checkInclusion(string s1, string s2) {
    int n = s1.length(), m = s2.length();

    if (n > m)
        return false;

    vector<int> f1(26, 0), f2(26, 0);

    // Fill frequency arrays
    for (int i = 0; i < n; i++) {
        f1[s1[i] - 'a']++;
        f2[s2[i] - 'a']++;
    }

    // Check first window
    if (f1 == f2)
        return true;

    // Sliding window
    for (int i = n; i < m; i++) {
        f2[s2[i] - 'a']++;         // add new char
        f2[s2[i - n] - 'a']--;    // remove old char

        if (f1 == f2)
            return true;
    }

    return false;
}
```

---

## ⚡ Important Notes

* Window size always remains equal to `s1.length()`
* `i - n` gives the outgoing character from previous window
* Frequency arrays work because strings contain only lowercase letters

---

## 🚀 Pattern

```text
Sliding Window + Frequency Array
```

---

## 🔥 Common Mistakes

* Generating permutations directly ❌
* Forgetting to remove old character from window ❌
* Using variable window size ❌

---

## 🧠 Memory Trick

```text
Fixed window → count freq → slide → compare
```


