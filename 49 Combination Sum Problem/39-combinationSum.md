# Leetcode 39 - Combination Sum

https://leetcode.com/problems/combination-sum/

## Problem

Given an array of **distinct** integers `candidates` and a target integer `target`, return all unique combinations where the chosen numbers sum to `target`.

A candidate can be chosen **unlimited** times.

---

## Intuition

For every number, we have only **2 choices**:

```text
Take the current number
or
Skip the current number
```

Unlike Subsets, when we **take** a number, we are allowed to use it again.

Therefore, after taking it, we **stay on the same index**.

---

## Approach

Suppose:

```cpp
candidates = [2,3,6,7]
target = 7
```

Current index:

```text
2
```

Two choices:

### Choice 1 : Take Current Number

```text
Current Combination

[]

↓

Take 2

↓

[2]
```

Target becomes:

```text
7 → 5
```

Since `2` can be reused:

```text
Stay on the same index.
```

---

### Choice 2 : Skip Current Number

Do not take `2`.

Move to the next candidate.

```text
2 skipped

↓

Try 3
```

---

## Why Stay on the Same Index?

Suppose:

```text
Target = 6

Current = 2
```

Take `2`:

```text
[]

↓

[2]
```

Can we still use another `2`?

Yes.

Therefore recursion becomes:

```cpp
combination(..., target-2, ..., i);
```

Notice:

```text
Index does not change.
```

Only when we decide to skip `2` do we move to:

```cpp
i + 1
```

---

## Why Don't We Need "Include Multiple Times"?

A common mistake is thinking we need three recursive calls:

```text
Include Once

Include Multiple Times

Exclude
```

We don't.

Reason:

When we include the current element and stay at the same index,

the next recursive call again has exactly the same two choices:

```text
Take

Skip
```

So multiple inclusion happens automatically.

Example:

```text
Take 2

↓

Take 2 again

↓

Take 2 again

↓

Skip 2
```

No separate recursion is needed.

---

## Why Don't We Need a Set?

The input contains:

```text
Distinct Candidates
```

Also, our recursion always moves forward.

Example:

```text
2 → 3 → 6 → 7
```

Once we skip a candidate, we never come back to it.

Therefore combinations like:

```text
[2,3]

and

[3,2]
```

can never both be generated.

Each combination is produced exactly once.

Hence:

```text
No duplicates are generated.
```

A `set` only increases memory usage and is unnecessary.

---

## Recursion Tree

Example:

```cpp
candidates = [2,3]
target = 7
```

```text
                    []
                 /        \
            Take 2       Skip 2
              |             |
            [2]            [3]
           /   \
      Take2   Skip2
        |
      [2,2]
        |
     Take2
        |
    [2,2,2]
```

Notice:

Taking keeps us at the same index.

Skipping moves to the next index.

---

## Base Cases

### Valid Combination

```cpp
if(target == 0)
```

Current combination sums to target.

Store it.

---

### Invalid Path

```cpp
if(i == candidates.size() || target < 0)
```

No more candidates or target became negative.

Stop recursion.

---

## Code

```cpp
void combination(vector<int>& arr,
                 int target,
                 vector<vector<int>>& ans,
                 vector<int>& curr,
                 int i)
{
    if (i == arr.size() || target < 0)
    {
        return;
    }

    if (target == 0)
    {
        ans.push_back(curr);
        return;
    }

    // Include
    curr.push_back(arr[i]);

    combination(arr,
                target - arr[i],
                ans,
                curr,
                i);

    // Backtrack
    curr.pop_back();

    // Exclude
    combination(arr,
                target,
                ans,
                curr,
                i + 1);
}

vector<vector<int>> combinationSum(vector<int>& arr,
                                   int target)
{
    vector<vector<int>> ans;
    vector<int> curr;

    combination(arr,
                target,
                ans,
                curr,
                0);

    return ans;
}
```

---

## Dry Run

Input:

```cpp
arr = [2,3]
target = 7
```

Start:

```text
[]
Target = 7
```

Take `2`

```text
[2]
Target = 5
```

Take `2`

```text
[2,2]
Target = 3
```

Take `2`

```text
[2,2,2]
Target = 1
```

Take `2`

```text
Target = -1
```

Return.

Backtrack.

Skip `2`.

Try `3`.

```text
[2,2,3]
Target = 0
```

Store answer.

---

## Complexity

Time Complexity:

```text
Exponential
```

The exact complexity depends on the target and branching.

Space Complexity:

```text
O(target)
```

due to recursion depth.

(Answer storage excluded.)

---

## Pattern

```text
Recursion

Backtracking

Combination Generation
```

---

## Memory Trick

```text
Current Candidate

↓

Take

↓

Stay on Same Index

↓

Skip

↓

Move to Next Index
```

Think:

```text
Choose

Explore

Undo
```

This is the standard pattern for:

- Combination Sum
- Combination Sum II
- Many recursive combination problems
