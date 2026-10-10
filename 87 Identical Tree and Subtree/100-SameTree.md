https://leetcode.com/problems/same-tree/

# LC 100 — Same Tree

## Problem

Determine whether two binary trees are identical in both **structure and node values**.

## Intuition

Use recursion to compare corresponding nodes of both trees.

- Both nodes are `nullptr` → same.
- Only one is `nullptr` → different.
- Values differ → different.
- Otherwise, compare left subtrees and right subtrees.

## Approach

1. **Base case:** If either node is `nullptr`, return `p == q`.
2. Recursively compare left children.
3. Recursively compare right children.
4. Return true only if both subtrees match and current values are equal.

## Code

```
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr) {
        return p == q;
    }

    bool isLeft = isSameTree(p->left, q->left);
    bool isRight = isSameTree(p->right, q->right);

    return isLeft && isRight && p->val == q->val;
}
```

## Key Observation

**Same values alone aren't enough.** Both the structure and corresponding node values must match.

`p == q` in the base case handles both situations:

- Both are null → `true`
- Exactly one is null → `false`

## Complexity

- **Time:** `O(n)`, where `n` is the number of nodes in the smaller tree in the worst case.
- **Auxiliary space:** `O(h)` for the recursion stack, where `h` is the tree height; `O(n)` in the worst case.

## Pattern to Remember

Tree comparison → **base cases + recursive left/right comparison + combine results**.

Clarify the time complexity notationAdd a small comparison example
