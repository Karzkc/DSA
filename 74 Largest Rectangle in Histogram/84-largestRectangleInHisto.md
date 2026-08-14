https://leetcode.com/problems/largest-rectangle-in-histogram/description/

# LC 84 - Largest Rectangle in Histogram

## Intuition

For every bar, imagine that this bar is the **shortest bar** in a rectangle.

To find the largest rectangle using `heights[i]`:

- Find the first smaller bar on the **left**.
- Find the first smaller bar on the **right**.
- Everything between them can have height `heights[i]`.

So:

```text
width = right[i] - left[i] - 1

area = height[i] × width
```

---

## Approach: Previous Smaller + Next Smaller

Use a **monotonic increasing stack**.

The stack stores **indices**, not heights.

### 1. Next Smaller Element

Traverse from right to left.

Remove indices whose heights are greater than or equal to the current height:

```cpp
while (!st.empty() && heights[st.top()] >= heights[i])
    st.pop();
```

Then:

```cpp
right[i] = st.empty() ? n : st.top();
```

`n` means there is no smaller element on the right.

---

### 2. Previous Smaller Element

Traverse from left to right using the same idea.

```cpp
while (!st.empty() && heights[st.top()] >= heights[i])
    st.pop();
```

Then:

```cpp
left[i] = st.empty() ? -1 : st.top();
```

`-1` means there is no smaller element on the left.

---

## Example

```text
heights = [2, 1, 5, 6, 2, 3]
```

For height `5`:

```text
        5
        |
1  |  5 | 6 | 2
      ↑       ↑
    left     right
```

Previous smaller:

```text
left = 1
```

Next smaller:

```text
right = 4
```

Therefore:

```text
width = 4 - 1 - 1
      = 2

area = 5 × 2
     = 10
```

---

## Important Detail

The stack stores **indices**:

```cpp
st.push(i);
```

Therefore, when comparing heights, use:

```cpp
heights[st.top()]
```

NOT:

```cpp
st.top()
```

This was an important bug to watch for.

---

## Why `>=`?

Use:

```cpp
heights[st.top()] >= heights[i]
```

Equal-height bars should be removed so that the current bar can extend across them and get the correct maximum width.

---

## Common Mistakes

- Starting the right-to-left loop at `n` instead of `n - 1`.
- Comparing `st.top()` directly with `heights[i]`.
- Forgetting to clear the stack between the two passes.
- Using incorrect width:
  ```cpp
  right[i] - left[i] - 1
  ```
- Forgetting that `-1` and `n` represent boundaries outside the array.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

Each index is pushed and popped at most once.

---

## Pattern Learned

### Monotonic Stack

For problems asking about the nearest:

- Smaller element
- Greater element
- Previous element
- Next element

consider a monotonic stack.

For LC 84:

```text
Previous Smaller
       +
Next Smaller
       ↓
    Width
       ↓
Height × Width
       ↓
Maximum Area
```

This PSE + NSE approach is also the foundation for **LC 85 - Maximal Rectangle**.
