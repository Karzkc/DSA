# LC 496 - Next Greater Element I

## Intuition

For every element in `nums2`, find the **first greater element to its right**.

Use a **monotonic decreasing stack**.

The stack stores possible next-greater elements.

---

## Approach

Traverse `nums2` from **right to left**.

For each number:

1. Remove all elements from the stack that are `<=` the current number.
2. If the stack is empty → no greater element exists → answer is `-1`.
3. Otherwise, the stack top is the next greater element.
4. Store the answer in a HashMap.
5. Push the current number.

Then traverse `nums1` and use the map to get each answer.

---

## Why Pop Smaller Elements?

Example:

```text
nums2 = [1, 3, 4, 2]
```

For `1`:

```text
stack = [3]
```

`3` is the first greater element.

For `3`:

```text
4 > 3
```

So `4` is its next greater element.

Any smaller element on the stack can never be useful because the current element itself blocks it.

---

## Why HashMap?

`nums1` is a subset of `nums2`.

We calculate NGE for **every element of nums2**:

```text
1 → 3
3 → 4
4 → -1
2 → -1
```

Store:

```cpp
unordered_map<int, int> m;
```

Then simply look up each `nums1` element.

---

## Key Pattern

### Monotonic Stack

When a problem asks for:

- Next greater element
- Next smaller element
- Previous greater element
- Previous smaller element

Think:

> **Monotonic Stack**

---

## Common Mistakes

- Traversing in the wrong direction.
- Forgetting to pop `<=` elements.
- Using an incorrectly sized result vector.
- Finding answers for `nums1` directly instead of using `nums2`.
- Forgetting that the stack contains **values**, not indices, in this problem.

---

## Complexity

Let:

- `n = nums1.size()`
- `m = nums2.size()`

Each element of `nums2` is pushed and popped at most once.

- **Time:** `O(n + m)`
- **Space:** `O(m)`

---

## Memory Trick

```text
Right → Left

Pop smaller

Top = Next Greater

Store in map

Push current
```

Then:

```text
nums1 → HashMap → Answer
```
