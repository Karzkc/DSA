https://leetcode.com/problems/first-missing-positive/

# LC 41 - First Missing Positive (Hard)

## Intuition

The smallest missing positive number must lie in the range **[1, n + 1]**, where `n` is the size of the array.

- If every number from `1` to `n` is present, the answer is `n + 1`.
- Otherwise, the answer is the first missing number within `[1, n]`.

Instead of using extra space, use the input array itself as a hash table by marking the presence of a number through negation.

---

## Approach

### Step 1: Remove irrelevant numbers

Replace every number that is:

- `<= 0`
- `> n`

with `n + 1`.

These numbers can never affect the answer.

```cpp
if(nums[i] <= 0 || nums[i] > n)
    nums[i] = n + 1;
```

---

### Step 2: Mark visited numbers

For every value `val`:

- Ignore it if `val > n`.
- Otherwise mark index `val - 1` as visited by making it negative.

```cpp
int val = abs(nums[i]);

if(val <= n)
{
    int idx = val - 1;

    if(nums[idx] > 0)
        nums[idx] = -nums[idx];
}
```

`abs()` is important because a number may already have been marked negative.

---

### Step 3: Find first positive index

The first positive index represents the first missing positive.

```cpp
for(int i = 0; i < n; i++)
{
    if(nums[i] > 0)
        return i + 1;
}
```

If every index is marked,

```cpp
return n + 1;
```

---

## Why It Works

The array itself acts as a hash table.

- Index `0` → Number `1`
- Index `1` → Number `2`
- Index `2` → Number `3`
- ...

If a number exists, its corresponding index becomes negative.

Positive index ⇒ Number never appeared.

---

## Key Observations

- The answer always lies in `[1, n + 1]`.
- Values outside this range are useless.
- Sign of each element stores whether a number exists.
- Always use `abs(nums[i])` because elements may already be negative.

---

## Common Mistakes

❌ Returning `nums[i]` instead of `i + 1`.

❌ Forgetting `abs()` while marking.

❌ Accessing `nums[val - 1]` when `val > n`.

❌ Negating an already negative value again.

❌ Forgetting that the array is being used as a hash table.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

---

## Pattern Learned

This is an example of **In-Place Hashing (Index Mapping)**.

Instead of using an external hash set, the array itself stores information about which numbers have been seen.

This pattern appears in several interview problems involving arrays with values constrained to a specific range.
