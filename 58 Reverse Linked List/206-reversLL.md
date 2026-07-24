https://leetcode.com/problems/reverse-linked-list/description/

# LC 206 - Reverse Linked List

## Intuition

Each node points to the next node.

To reverse the list, make every node point to its **previous** node instead.

The challenge is not losing the rest of the list while changing pointers.

---

## Approach

Maintain three pointers:

```text
prev <- curr -> next
```

At every step:

1. Save `curr->next` in `next`.
2. Reverse the link:
   ```cpp
   curr->next = prev;
   ```
3. Move all pointers one step ahead.

Repeat until `curr` becomes `nullptr`.

Finally, `prev` points to the new head.

---

## Pointer Movement

Before:

```text
nullptr <- 1 -> 2 -> 3 -> 4
           ^
         curr
```

After one iteration:

```text
nullptr <- 1    2 -> 3 -> 4
           ^    ^
         prev  curr
```

Repeat until the entire list is reversed.

---

## Why Store `next`?

After:

```cpp
curr->next = prev;
```

the original next node is lost.

So always save:

```cpp
next = curr->next;
```

before changing the link.

---

## Common Mistakes

❌ Forgetting to store `next` first.

❌ Returning `head` instead of `prev`.

❌ Updating pointers in the wrong order.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

---

## Pattern

Whenever a linked list asks to **reverse** nodes, think:

```text
prev
curr
next
```

These three pointers solve most iterative reversal problems.

---

## Memory Trick

```text
Save Next

↓

Reverse Link

↓

Move Forward
```

Think:

> **Store → Reverse → Shift**
