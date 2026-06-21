https://leetcode.com/problems/subsets/description/?envType=problem-list-v2&envId=backtracking

# Subsets

## Problem

Given an integer array `nums`, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

---

## Intuition

For every element we have exactly two choices:

```text
Include it
Exclude it
```

Example:

```cpp
nums = [1,2]
```

Choices:

```text
Take 1 / Don't Take 1
Take 2 / Don't Take 2
```

Subsets:

```text
[]
[1]
[2]
[1,2]
```

---

## Recursion Tree

```text
                []
              /    \
            [1]     []
           /   \   /  \
      [1,2] [1] [2] []
```

Each level represents a decision for one element.

---

## Approach

For every index:

### Include Current Element

```cpp
curr.push_back(nums[i]);
```

Move to next index.

---

### Backtrack

Remove the element before exploring another choice.

```cpp
curr.pop_back();
```

---

### Exclude Current Element

Skip the current element and move to the next index.

---

## Base Case

When:

```cpp
i == nums.size()
```

all decisions have been made.

Store the current subset:

```cpp
ans.push_back(curr);
```

---

## Code

```cpp
void getSubsets(vector<int>& nums,
                vector<vector<int>>& ans,
                vector<int>& curr,
                int i)
{
    if (i == nums.size())
    {
        ans.push_back(curr);
        return;
    }

    // Include
    curr.push_back(nums[i]);
    getSubsets(nums, ans, curr, i + 1);

    // Backtrack
    curr.pop_back();

    // Exclude
    getSubsets(nums, ans, curr, i + 1);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> curr;

    getSubsets(nums, ans, curr, 0);

    return ans;
}
```

---

## Dry Run

Input:

```cpp
nums = [1,2]
```

Start:

```cpp
curr = []
```

Include 1:

```cpp
curr = [1]
```

Include 2:

```cpp
curr = [1,2]
```

Store:

```text
[1,2]
```

Backtrack:

```cpp
curr = [1]
```

Exclude 2:

```text
[1]
```

Backtrack:

```cpp
curr = []
```

Include 2:

```text
[2]
```

Exclude 2:

```text
[]
```

Final Answer:

```text
[1,2]
[1]
[2]
[]
```

---

## Complexity

Number of subsets:

```text
2^n
```

Time Complexity:

```text
O(n × 2^n)
```

Reason:

- Total subsets = `2^n`
- Copying each subset can take `O(n)`

Space Complexity:

```text
O(n)
```

due to recursion stack.

---

## Pattern

```text
Recursion
Backtracking
Power Set Generation
```

---

## Key Idea

For every element:

```text
Take it
or
Don't take it
```

Recursively explore both choices.
