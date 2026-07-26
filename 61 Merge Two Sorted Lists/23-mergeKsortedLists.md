https://leetcode.com/problems/merge-k-sorted-lists/

# LC 23 - Merge k Sorted Lists (Hard)

## Intuition

This is simply **Merge Sort + LC 21 (Merge Two Sorted Lists)**.

- Divide the `k` lists into two halves.
- Recursively merge each half.
- Merge the two resulting lists using LC 21.

---

## Approach

1. Base case:
   - If only one list remains, return it.
2. Find the middle.
3. Recursively merge left half.
4. Recursively merge right half.
5. Merge both using `mergeTwoLists()`.

---

## Key Observation

Treat the vector of linked lists exactly like Merge Sort treats an array.

```text
L1 L2 L3 L4

↓

(L1+L2)   (L3+L4)

↓

Final Merge
```

---

## Common Mistakes

- Forgetting to handle empty `lists`.
- Using `mid - 1` instead of `mid`.
- Writing a new merge function instead of reusing LC 21.

---

## Complexity

- **Time:** `O(N log k)`
  - `N` = Total number of nodes
  - `k` = Number of linked lists

- **Space:** `O(log k)` (recursion stack)
