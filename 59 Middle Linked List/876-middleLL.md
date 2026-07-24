https://leetcode.com/problems/middle-of-the-linked-list/description/

# LC 876 - Middle of the Linked List

## Intuition

The middle depends only on the **length** of the linked list.

So:

1. Count the total nodes.
2. Move `length / 2` steps from the head.
3. That node is the answer.

---

## Approach

- Traverse once to find the length.
- Calculate the middle index.
- Traverse again to reach the middle node.
- Return it.

---

## Why `len / 2 + 1`?

For 0-based indexing, the middle node is at index:

```text
len / 2
```

Since your loop starts from **1**, you use:

```cpp
mid = len / 2 + 1;
```

### Example

```text
1 → 2 → 3 → 4

len = 4
mid = 3
Answer = 3
```

LeetCode asks for the **second middle** when there are two middles.

---

## Common Mistakes

❌ Using `floor(len / 2)`

Integer division already performs floor.

```cpp
len / 2
```

is enough.

---

❌ Returning the first middle for even-length lists.

The expected answer is the **second middle**.

---

## Complexity

- **Time:** `O(n)` (2 traversals)
- **Space:** `O(1)`

---

## Better Approach

Use **Slow & Fast Pointers**.

- Slow moves 1 step.
- Fast moves 2 steps.

When `fast` reaches the end, `slow` is automatically at the middle.

This finds the answer in **one traversal** and is the standard interview solution.

---

## Pattern

Whenever a linked list asks for:

- Middle node
- Split list
- Detect cycle
- kth node from end

Think:

> **Slow & Fast Pointers**
