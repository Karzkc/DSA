https://leetcode.com/problems/merge-two-sorted-lists/

# LC 21 - Merge Two Sorted Lists

## Intuition

Both lists are already sorted.

At every step, compare the first node of each list.

- Pick the smaller node.
- Recursively merge the remaining lists.
- Attach the returned list to the chosen node.

Think of it as repeatedly choosing the smallest available node.

---

## Approach

1. If one list becomes empty, return the other list.
2. Compare `list1->val` and `list2->val`.
3. Choose the smaller node.
4. Recursively merge the remaining part.
5. Return the chosen node as the head.

---

## Why the Base Case?

If one list is exhausted:

```text
List1 : nullptr

List2 : 4 → 7 → 9
```

The remaining nodes are already sorted.

Simply return the non-null list.

```cpp
if(list1 == nullptr) return list2;
if(list2 == nullptr) return list1;
```

---

## Recursion Flow

Example:

```text
List1 : 1 → 3 → 5

List2 : 2 → 4 → 6
```

Compare:

```text
1 < 2
```

Choose:

```text
1
```

Now solve:

```text
3 → 5

2 → 4 → 6
```

Again,

```text
2 < 3
```

Choose:

```text
2
```

Continue until one list becomes empty.

Final result:

```text
1 → 2 → 3 → 4 → 5 → 6
```

---

## Common Mistakes

❌ Wrong base case:

```cpp
return list1 == nullptr ? list1 : list2;
```

When `list1` is `nullptr`, this returns `nullptr` instead of the remaining list.

Correct:

```cpp
return list1 == nullptr ? list2 : list1;
```

or

```cpp
if(list1 == nullptr) return list2;
if(list2 == nullptr) return list1;
```

---

## Complexity

- **Time:** `O(n + m)`
- **Space:** `O(n + m)` (recursive call stack)

---

## Pattern

Whenever two sorted structures need to be merged:

- Compare current elements.
- Choose the smaller one.
- Recursively merge the rest.

This same idea appears in:

- Merge Sort
- Merge K Sorted Lists
- Merge Two Sorted Arrays (iterative)

---

## Memory Trick

```text
Compare

↓

Choose Smaller

↓

Merge Remaining

↓

Return Chosen Node
```

Think:

> **Pick → Recurse → Attach**
