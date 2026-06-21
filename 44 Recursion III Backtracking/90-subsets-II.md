https://leetcode.com/problems/subsets-ii/description/

# Subsets II

## Problem

Given an integer array `nums` that may contain duplicates, return all possible subsets without duplicate subsets.

Example:

```cpp
nums = [1,2,2]
```

Output:

```text
[]
[1]
[2]
[1,2]
[2,2]
[1,2,2]
```

---

## Difference from Subsets I

In Subsets I:

```cpp
nums = [1,2,3]
```

All elements are unique.

Every Take / Skip path produces a unique subset.

---

In Subsets II:

```cpp
nums = [1,2,2]
```

Two identical values exist.

Without special handling:

```text
Take first 2, Skip second 2  -> [2]

Skip first 2, Take second 2  -> [2]
```

The same subset is generated twice.

We must avoid this.

---

## Key Idea

First sort the array:

```cpp
sort(nums.begin(), nums.end());
```

After sorting:

```cpp
[1,2,2,2,3]
```

All duplicates become adjacent.

This allows us to skip duplicate values during recursion.

---

## Approach

For every element:

```text
Include it
or
Exclude it
```

### Include Branch

Take the current element and move to the next index.

```cpp
curr.push_back(arr[i]);
getSubsets(arr, ans, curr, i + 1);
```

---

### Backtrack

Undo the choice.

```cpp
curr.pop_back();
```

---

### Skip Duplicates

When choosing the Exclude branch:

Move past all duplicate occurrences.

```cpp
int idx = i + 1;

while(idx < arr.size() &&
      arr[idx] == arr[idx - 1])
{
    idx++;
}
```

Now:

```cpp
getSubsets(arr, ans, curr, idx);
```

This ensures duplicate subsets are not generated.

---

## Why Does This Work?

Example:

```cpp
[1,2,2]
```

Suppose we exclude the first `2`.

Instead of exploring:

```text
Skip first 2
Take second 2
```

we skip all identical `2`s together.

Thus:

```text
[2]
```

is generated only once.

---

## Recursion Tree

Input:

```cpp
[1,2,2]
```

Tree:

```text
                    []
                 /      \
               [1]       []
              /   \     /   \
           [1,2]  [1] [2]   []
           /  \
      [1,2,2] [1,2]
```

Duplicate branches are skipped.

---

## Base Case

When:

```cpp
i == arr.size()
```

Store the current subset.

```cpp
ans.push_back(curr);
```

---

## Code

```cpp
void getSubsets(vector<int>& arr,
                vector<vector<int>>& ans,
                vector<int>& curr,
                int i)
{
    if (i == arr.size())
    {
        ans.push_back(curr);
        return;
    }

    // Include
    curr.push_back(arr[i]);
    getSubsets(arr, ans, curr, i + 1);

    // Backtrack
    curr.pop_back();

    // Skip duplicates
    int idx = i + 1;

    while (idx < arr.size() &&
           arr[idx] == arr[idx - 1])
    {
        idx++;
    }

    // Exclude
    getSubsets(arr, ans, curr, idx);
}

vector<vector<int>> subsetsWithDup(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    vector<int> curr;
    vector<vector<int>> ans;

    getSubsets(arr, ans, curr, 0);

    return ans;
}
```

---

## Dry Run

Input:

```cpp
[1,2,2]
```

### Include 1

```text
[1]
```

### Include 2

```text
[1,2]
```

### Include 2

```text
[1,2,2]
```

Store.

Backtrack.

### Exclude duplicate 2

Skip all equal `2`s.

Store:

```text
[1,2]
```

Backtrack.

Store:

```text
[1]
```

Similarly for other branches.

Final Answer:

```text
[]
[1]
[2]
[1,2]
[2,2]
[1,2,2]
```

---

## Complexity

Worst Case:

```text
O(n × 2^n)
```

Same as normal subsets.

Reason:

- Up to `2^n` subsets.
- Copying each subset may take `O(n)`.

Space Complexity:

```text
O(n)
```

for recursion stack.

---

## Pattern

```text
Recursion
Backtracking
Duplicate Skipping
```

---

## Common Mistakes

### Forgetting to Sort

```cpp
sort(nums.begin(), nums.end());
```

Without sorting, duplicates won't be adjacent.

---

### Not Skipping Duplicates

Leads to repeated subsets.

---

### Skipping Duplicates in Include Branch

Duplicates should only be skipped in the Exclude branch.

Otherwise valid subsets are lost.

---

## Memory Trick

```text
Take Current Element

Backtrack

Skip All Equal Elements

Explore Exclude Branch
```

This is the standard recursion pattern for:

```text
Subsets II
Combination Sum II
Combination Problems with Duplicates
```
