https://leetcode.com/problems/subtree-of-another-tree/

# LC 572 — Subtree of Another Tree

## Problem

Determine whether `subRoot` exists as a subtree inside `root`, with the **same structure and node values**.

## Intuition

Reuse **LC 100 — Same Tree**.

- `isSubtree()` searches every node in `root` as a potential starting point.
- When values match, `isSameTree()` checks whether the entire subtree matches.
- If it doesn't match, search the left and right subtrees.

## Approach

1. If either tree is `nullptr`, return `root == subRoot`.
2. If current values match, call `isSameTree(root, subRoot)`.
3. If identical, return `true`.
4. Otherwise, recursively search `root->left` and `root->right`.

## Code

```
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr || subRoot == nullptr) {
        return root == subRoot;
    }

    if (root->val == subRoot->val &&
        isSameTree(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}
```

## Key Observation

**LC 572 = LC 100 + tree traversal.**

- `isSubtree()` finds a possible matching root.
- `isSameTree()` verifies the complete subtree.

The `||` short-circuits: if the left subtree contains a match, the right subtree doesn't need to be searched.

## Complexity

Let `n` be the number of nodes in `root` and `m` the number of nodes in `subRoot`.

- **Time:** `O(n × m)` worst case, because `isSameTree()` may examine up to `m` nodes at each candidate node.
- **Auxiliary space:** `O(h₁ + h₂)` for recursion, where `h₁` and `h₂` are the respective tree heights.

## Pattern to Remember

Tree matching problems → **traverse candidate roots + compare entire subtrees**.

Show the missing isSameTree helperClarify the empty-tree edge cases
