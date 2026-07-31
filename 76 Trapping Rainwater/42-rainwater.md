# LC 42 - Trapping Rain Water (Hard)

## Intuition

A bar can trap water **only if there is a taller bar on both its left and right**.

For every index:

```text
Water at i = min(Max Left, Max Right) - height[i]
```

The shorter of the two boundaries determines the water level.

---

# Approach 1: Prefix & Suffix Maximum Arrays

## Idea

Precompute:

- `left[i]` = Maximum height from `0...i`
- `right[i]` = Maximum height from `i...n-1`

Then,

```cpp
water = min(left[i], right[i]) - height[i];
```

Add this for every index.

---

## Steps

### 1. Build Left Max array

```text
Height : 0 1 0 2 1 0 1 3

Left   : 0 1 1 2 2 2 2 3
```

---

### 2. Build Right Max array

```text
Height : 0 1 0 2 1 0 1 3

Right  : 3 3 3 3 3 3 3 3
```

(Example shortened for illustration.)

---

### 3. Compute water

For every index:

```cpp
ans += min(left[i], right[i]) - height[i];
```

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

---

# Approach 2: Two Pointers (Optimal)

## Key Observation

At any point,

```text
leftMax
        |
        v
... i ............. j ...
                    ^
                    |
                 rightMax
```

Only the **smaller boundary** matters.

### Case 1

```text
leftMax < rightMax
```

No matter what exists further on the right,

the water at `i` is completely determined by `leftMax`.

So,

```cpp
water = leftMax - height[i];
```

Move the left pointer.

---

### Case 2

```text
rightMax <= leftMax
```

Now the right boundary limits the water.

```cpp
water = rightMax - height[j];
```

Move the right pointer.

---

## Why does this work?

Suppose

```text
leftMax = 5
rightMax = 8
```

The water level can never exceed `5`.

Whether the actual right maximum is `8`, `10`, or `100` doesn't matter because

```text
min(5, anything ≥ 5) = 5
```

So we already know the answer for the left side and can safely process it.

The same logic applies symmetrically when `rightMax <= leftMax`.

---

## Algorithm

```text
Initialize:

left = 0
right = n - 1
leftMax = 0
rightMax = 0

While left < right

    Update leftMax
    Update rightMax

    If leftMax < rightMax
        answer += leftMax - height[left]
        left++

    Else
        answer += rightMax - height[right]
        right--
```

---

## Key Observations

- Water depends on the **shorter boundary**, not the taller one.
- Prefix/Suffix arrays precompute the boundaries.
- Two pointers compute the same values on the fly.
- Once one side has the smaller maximum, its trapped water is fixed.

---

## Common Mistakes

❌ Using `max(leftMax, rightMax)` instead of `min()`.

❌ Forgetting to update `leftMax`/`rightMax` before calculating water.

❌ Moving the wrong pointer.

❌ Thinking both boundaries must be known exactly before processing.

❌ Confusing current height with current maximum.

---

## Complexity

### Prefix & Suffix

- **Time:** `O(n)`
- **Space:** `O(n)`

### Two Pointers (Optimal)

- **Time:** `O(n)`
- **Space:** `O(1)`

---

## Pattern Learned

### Prefix/Suffix Maximum

Precompute information from both directions to answer each position in `O(1)`.

Examples:

- Trapping Rain Water
- Product of Array Except Self
- Left/Right Maximum problems

---

### Two Pointer Boundary Technique

When the answer depends on the **minimum of two boundaries**, process the side with the smaller boundary first because its answer is already determined.

This is a classic optimization pattern that converts an `O(n)` space solution into an `O(1)` space solution.
