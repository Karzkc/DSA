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

## Better Approach: Fast & Slow Pointers

This is the standard approach for solving the middle-of-linked-list problem.

- `slow` moves 1 step at a time.
- `fast` moves 2 steps at a time.
- Because `fast` moves twice as fast, when `fast` reaches the end, `slow` will be exactly at the middle node.

### Why this works

`fast` covers double the distance of `slow`.
So if the list has `n` nodes:

- `slow` reaches the middle after about `n/2` steps
- `fast` reaches the end after `n` steps

That is why `slow` ends up at the middle node.

---

## Optimal Approach (C++)

```cpp
ListNode *middleNodeOptimal(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
```

### Explanation

- `slow` starts from the head and moves one node at a time.
- `fast` starts from the head and moves two nodes at a time.
- When `fast` reaches the end, `slow` is at the middle node.
- This uses only one traversal and is the most optimal solution.

### Example

For a linked list:

```text
1 → 2 → 3 → 4 → 5
```

- `slow` goes: 1 → 2 → 3
- `fast` goes: 1 → 3 → 5

So `slow` stops at `3`, which is the middle node.

### Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

---

## Pattern

Whenever a linked list asks for:

- Middle node
- Split list
- Detect cycle
- kth node from end

Think:

> **Slow & Fast Pointers**
