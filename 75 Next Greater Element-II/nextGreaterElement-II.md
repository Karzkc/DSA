https://leetcode.com/problems/next-greater-element-ii/description/

# LC 503 - Next Greater Element II

## Intuition

Same idea as **LC 496 - Next Greater Element I**, but the array is **circular**.

Example:

```text
[1, 2, 1]

For the last 1:
1 → 2
```

In a normal array, there is nothing to its right.

In a circular array, after reaching the end, we continue from the beginning.

---

## Approach

Pretend the array is written twice:

```text
[1, 2, 1, 1, 2, 1]
```

Instead of actually creating a second array, use:

```cpp
for(int i = 2*n - 1; i >= 0; i--)
```

Get the actual array index using:

```cpp
int idx = i % n;
```

Then apply the normal monotonic stack logic.

---

## Stack Logic

Traverse from right to left.

For every element:

1. Remove all elements `<=` the current element.
2. Stack top is then the next greater element.
3. If stack is empty → answer is `-1`.
4. Push the current index.

```cpp
while(!s.empty() && nums[s.top()] <= nums[idx])
    s.pop();

ans[idx] = s.empty() ? -1 : nums[s.top()];

s.push(idx);
```

---

## Why Traverse Twice?

Because the array wraps around.

```text
1  2  1 | 1  2  1
        ↑
     wrap around
```

The second copy allows elements near the end to find greater elements near the beginning.

We don't actually create the second array; `% n` simulates it.

---

## Why Store Indices?

The stack stores:

```cpp
stack<int>
```

where each value is an **index**.

Therefore:

```cpp
nums[s.top()]
```

gives the actual value.

This is useful because the same index can be used during both traversals.

---

## Key Pattern

```text
Circular Array
      ↓
Traverse 2 × n
      ↓
i % n → actual index
      ↓
Monotonic Decreasing Stack
      ↓
Next Greater Element
```

---

## Common Mistakes

- Traversing only `n` elements.
- Forgetting the `% n`.
- Creating an actual second array unnecessarily.
- Storing values when you need indices.
- Forgetting to pop elements `<=` the current value.
- Confusing the circular traversal with physically modifying the array.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

Even though we loop `2n` times, that is still `O(n)`.

---

## Pattern Learned

### Circular Array + Monotonic Stack

For a **Next Greater/Smaller Element** problem on a circular array:

```cpp
for(int i = 2*n - 1; i >= 0; i--)
{
    int idx = i % n;
    // normal monotonic stack logic
}
```

This same "traverse twice + modulo" technique is useful for other circular-array problems.
