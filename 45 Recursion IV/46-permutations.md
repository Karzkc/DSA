https://leetcode.com/problems/permutations/submissions/2043752645/

# Permutations

## Problem

Given an array `nums` of distinct integers, return all possible permutations.

A permutation is an arrangement of all elements in a different order.

Example:

```cpp
nums = [1,2,3]
```

Output:

```text
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
```

---

## Intuition

For every position in the array, choose which element should be placed there.

Example:

```cpp
[1,2,3]
```

For position `0`, we can place:

```text
1
2
3
```

After fixing one element, recursively solve the remaining positions.

---

## Key Idea

Instead of creating a new array every time, we use swapping.

At index `i`:

```text
Choose an element
Place it at position i
Recursively solve remaining positions
Backtrack
```

---

## Approach

Suppose:

```cpp
arr = [1,2,3]
```

At:

```cpp
i = 0
```

Try:

```cpp
swap(0,0)
swap(0,1)
swap(0,2)
```

This places:

```text
1 at position 0
2 at position 0
3 at position 0
```

Then recursively generate permutations for the remaining positions.

---

## Why Backtracking?

Suppose:

```cpp
arr = [1,2,3]
```

We do:

```cpp
swap(arr[0], arr[1]);
```

Array becomes:

```cpp
[2,1,3]
```

After recursion finishes, we need the original array back:

```cpp
[1,2,3]
```

so we can try another choice.

Therefore:

```cpp
swap(arr[0], arr[1]);
```

is performed again.

This restores the original state.

```text
Choose
Recurse
Undo Choice
```

This is Backtracking.

---

## Recursion Tree

Input:

```cpp
[1,2,3]
```

Tree:

```text
                    [1,2,3]
                  /    |    \
                 /     |     \
                /      |      \
            [1]      [2]      [3]
           /  \      /  \      /  \
       [1,2] [1,3] [2,1] [2,3] [3,1] [3,2]
```

Each level fixes one position.

---

## Base Case

When:

```cpp
i == arr.size()
```

all positions have been fixed.

Store the permutation:

```cpp
ans.push_back(arr);
```

---

## Code

```cpp
void getPermutation(vector<int>& arr,
                    vector<vector<int>>& ans,
                    int i)
{
    if (i == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int j = i; j < arr.size(); j++)
    {
        swap(arr[i], arr[j]);

        getPermutation(arr, ans, i + 1);

        swap(arr[i], arr[j]);
    }
}

vector<vector<int>> permute(vector<int>& arr)
{
    vector<vector<int>> ans;

    getPermutation(arr, ans, 0);

    return ans;
}
```

---

## Dry Run

Input:

```cpp
[1,2,3]
```

### First Choice

```cpp
swap(0,0)
```

Array:

```cpp
[1,2,3]
```

Generate:

```text
[1,2,3]
[1,3,2]
```

---

### Second Choice

```cpp
swap(0,1)
```

Array:

```cpp
[2,1,3]
```

Generate:

```text
[2,1,3]
[2,3,1]
```

---

### Third Choice

```cpp
swap(0,2)
```

Array:

```cpp
[3,2,1]
```

Generate:

```text
[3,1,2]
[3,2,1]
```

---

## Complexity

Number of permutations:

```text
n!
```

Time Complexity:

```text
O(n × n!)
```

Reason:

- Total permutations = `n!`
- Copying each permutation takes `O(n)`

Space Complexity:

```text
O(n)
```

due to recursion stack.

(Answer storage not included.)

---

## Pattern

```text
Recursion
Backtracking
Swap Technique
```

---

## Common Mistakes

### Forgetting Backtracking

Wrong:

```cpp
swap(arr[i], arr[j]);
getPermutation(...);
```

Without swapping back, future recursive calls work on a modified array.

---

### Incorrect Base Case

Use:

```cpp
if(i == arr.size())
```

to store a complete permutation.

---

### Starting Loop from 0

Wrong:

```cpp
for(int j = 0; j < n; j++)
```

Correct:

```cpp
for(int j = i; j < n; j++)
```

Only the current position should be fixed.

---

## Memory Trick

```text
Fix Position i

Try every element

Swap
↓
Recurse
↓
Swap Back
```

Think:

```text
Choose
Explore
Undo
```

This same pattern is used in:

```text
Permutations
Permutations II
N Queens
Sudoku Solver
Word Search
```
