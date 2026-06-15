https://leetcode.com/problems/find-the-duplicate-number/description/

# Find the Duplicate Number

## Problem

Given an array `nums` containing:

```text
n + 1 integers
```

where every integer is in the range:

```text
[1, n]
```

There is only one repeated number.

Return that duplicate number.

---

# Solution 1: Hash Set

## Intuition

Traverse the array and keep track of numbers already seen.

If a number appears again, it is the duplicate.

---

## Approach

1. Create an `unordered_set`.
2. Traverse the array.
3. If current number already exists in the set:
   - return it.
4. Otherwise insert it into the set.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

---

## Code

```cpp
int findDuplicate(vector<int>& nums) {

    unordered_set<int> seen;

    for (int num : nums) {

        if (seen.count(num)) {
            return num;
        }

        seen.insert(num);
    }

    return -1;
}
```

---

## Pattern

```text
Hashing
Duplicate Detection
```

---

# Solution 2: Floyd's Cycle Detection (Optimal)

## Key Observation

Numbers are in range:

```text
1 to n
```

Treat:

```cpp
index -> value
```

as a linked list.

Example:

```cpp
nums = [1,3,4,2,2]
```

Representation:

```text
0 → 1
1 → 3
3 → 2
2 → 4
4 → 2
```

Notice:

```text
2 → 4 → 2 → 4 → ...
```

A cycle exists.

The duplicate number is exactly the node where the cycle begins.

---

## Why Does a Cycle Exist?

Array size:

```text
n + 1
```

Possible values:

```text
1 to n
```

More positions than values.

By the Pigeonhole Principle:

```text
At least one value must repeat.
```

That repeated value creates a cycle.

---

# Phase 1: Find Meeting Point

Use:

```cpp
slow = nums[slow]
fast = nums[nums[fast]]
```

Slow moves:

```text
1 step
```

Fast moves:

```text
2 steps
```

Eventually they meet inside the cycle.

---

## Example

```cpp
nums = [1,3,4,2,2]
```

Start:

```text
slow = 1
fast = 1
```

Move:

```text
slow = 3
fast = 2

slow = 2
fast = 2
```

Meeting point found.

---

# Phase 2: Find Cycle Entry

Move:

```cpp
slow = nums[0]
```

Keep fast at meeting point.

Now move both one step:

```cpp
slow = nums[slow]
fast = nums[fast]
```

The point where they meet again is the duplicate number.

---

## Why Does This Work?

Let:

```text
L = distance from start to cycle
C = cycle length
```

When slow and fast meet:

```text
fast travels twice as far as slow
```

This mathematical relationship guarantees that resetting one pointer to the start causes both pointers to meet at the cycle entry.

The cycle entry is the duplicate number.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

---

## Code

```cpp
int findDuplicate(vector<int>& nums) {

    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
```

---

# Why Is This Better?

Hash Set:

```text
Time  : O(n)
Space : O(n)
```

Floyd:

```text
Time  : O(n)
Space : O(1)
```

No extra memory is used.

---

# Pattern

```text
Linked List Cycle Detection
Floyd's Tortoise and Hare
```

---

# Common Mistakes

- Using sorting (`O(n log n)`) ❌
- Forgetting to reset slow pointer after first meeting ❌
- Moving fast by only one step ❌
- Confusing meeting point with duplicate number ❌

---

# Memory Trick

```text
Treat array as linked list

Find cycle
Find cycle entrance

Cycle entrance = Duplicate Number
```
