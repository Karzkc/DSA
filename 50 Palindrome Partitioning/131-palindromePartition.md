https://leetcode.com/problems/palindrome-partitioning/

# Leetcode 131 - Palindrome Partitioning

## Problem

Given a string `s`, partition it such that every substring in the partition is a palindrome.

Return all possible palindrome partitions.

Example:

```cpp
Input:
s = "aab"

Output:
[
  ["a","a","b"],
  ["aa","b"]
]
```

---

# Intuition

At every step, we decide:

```text
Where should the current partition end?
```

We try every possible prefix of the remaining string.

If the prefix is a palindrome:

- Choose it.
- Solve for the remaining string.
- Backtrack.

---

# Key Observation

Suppose:

```text
s = "aab"
```

Possible first partitions:

```text
"a"   -> palindrome ✅

"aa"  -> palindrome ✅

"aab" -> not palindrome ❌
```

Only palindrome prefixes are explored.

---

# Approach

For the remaining string:

```text
Current String

↓

Generate every prefix

↓

Is prefix palindrome?

↓

Yes

↓

Store in current partition

↓

Solve remaining suffix

↓

Backtrack
```

---

# Example

Input:

```text
"aab"
```

Possible prefixes:

```text
"a"
"aa"
"aab"
```

Only:

```text
"a"
"aa"
```

are valid.

---

Choose:

```text
"a"
```

Remaining string:

```text
"ab"
```

Again:

```text
"a"

"ab"
```

Only:

```text
"a"
```

is palindrome.

Remaining:

```text
"b"
```

Store:

```text
["a","a","b"]
```

Backtrack.

Now choose:

```text
"aa"
```

Remaining:

```text
"b"
```

Store:

```text
["aa","b"]
```

---

# Recursion Tree

```text
                  "aab"
               /          \
            "a"          "aa"
             |             |
            "ab"          "b"
             |             |
            "a"           "b"
             |
            "b"

Solutions:

[a,a,b]
[aa,b]
```

---

# Base Case

When:

```cpp
s.size() == 0
```

Entire string has been partitioned.

Store:

```cpp
ans.push_back(curr);
```

---

# Palindrome Check

Before choosing a substring:

```cpp
checkPalindrome(currStr)
```

If:

```text
True
```

continue recursion.

Otherwise:

```text
Skip this branch.
```

---

# Code

```cpp
bool checkPalindrome(const string& currStr)
{
    int s = 0;
    int e = currStr.size() - 1;

    while (s < e)
    {
        if (currStr[s++] != currStr[e--])
            return false;
    }

    return true;
}

void getPartition(vector<vector<string>>& ans,
                  string s,
                  vector<string>& curr)
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

            getPartition(ans,
                         s.substr(i + 1),
                         curr);

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
```

---

# Dry Run

Input:

```text
"aab"
```

Current:

```text
[]
```

Choose:

```text
"a"
```

Current:

```text
["a"]
```

Remaining:

```text
"ab"
```

Choose:

```text
"a"
```

Current:

```text
["a","a"]
```

Remaining:

```text
"b"
```

Choose:

```text
"b"
```

Current:

```text
["a","a","b"]
```

Store answer.

Backtrack.

Choose:

```text
"aa"
```

Current:

```text
["aa"]
```

Remaining:

```text
"b"
```

Store:

```text
["aa","b"]
```

---

# Complexity

Let:

```text
n = length of string
```

Time Complexity:

```text
O(n × 2^n)
```

Reason:

- Up to `2^n` possible partitions.
- Each palindrome check may take `O(n)`.

Space Complexity:

```text
O(n)
```

due to recursion stack and current partition.

(Answer storage excluded.)

---

# Pattern

```text
Recursion

Backtracking

Partitioning
```

---

# Why Backtracking?

Suppose:

Current partition:

```text
["aa"]
```

Now choose:

```text
"b"
```

Current:

```text
["aa","b"]
```

After recursion:

```cpp
curr.pop_back();
```

removes `"b"` so another partition can be explored.

---

# Memory Trick

```text
Remaining String

↓

Try Every Prefix

↓

Palindrome?

↓

Choose Prefix

↓

Solve Remaining Suffix

↓

Backtrack
```

Think:

```text
Choose

Explore

Undo
```

---

# Similar Problems

- Subsets
- Combination Sum
- Combination Sum II
- N-Queens
- Sudoku Solver
- Rat in a Maze
- Palindrome Partitioning

All follow the same Backtracking pattern:

```text
Choose

↓

Recurse

↓

Backtrack
```
