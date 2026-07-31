https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

# LC 430 - Flatten a Multilevel Doubly Linked List

## Intuition

Whenever a node has a **child**, that child list should be inserted **between** the current node and its next node.

Think of it as:

```text
Current -> Next

becomes

Current -> Child List -> Next
```

The child itself may again contain children, so recursively flatten it first.

---

## Approach

For every node:

1. If there is no child, move to the next node.
2. If a child exists:
   - Save the original `next` node.
   - Recursively flatten the child list.
   - Attach the flattened child after the current node.
   - Remove the child pointer.
   - Traverse to the end of the flattened child list.
   - Connect the saved `next` node.

Continue until the end of the list.

---

## Visualization

Before

```text
1 ⇄ 2 ⇄ 3 ⇄ 4
      |
      5 ⇄ 6
```

After flattening child

```text
1 ⇄ 2 ⇄ 5 ⇄ 6 ⇄ 3 ⇄ 4
```

If node 5 also has a child, recursion flattens it first before reconnecting.

---

## Key Observations

- Always save the original `next` node before changing pointers.
- Recursively flatten the child list first.
- `child` pointer must become `nullptr`.
- After attaching the child list, move to its tail before reconnecting the original next node.

---

## Common Mistakes

❌ Forgetting to save `next`.

❌ Forgetting

```cpp
curr->child = nullptr;
```

❌ Forgetting to update `prev` pointers.

❌ Connecting the original next before reaching the tail of the child list.

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(d)` (recursion stack)

`d` = Maximum nesting depth of child lists.

---

## Pattern Learned

### DFS on Linked Structures

Whenever a linked structure contains another linked structure (child pointers):

1. Process the child recursively.
2. Splice it into the current structure.
3. Restore the remaining links.

This pattern appears in:

- Multilevel Linked List Flattening
- Tree Flattening
- DFS-based structure transformations
