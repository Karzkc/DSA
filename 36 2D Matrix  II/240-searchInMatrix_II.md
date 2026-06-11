https://leetcode.com/problems/search-a-2d-matrix-ii/

# Search a 2D Matrix II

## Intuition

The matrix has the following properties:

- Each row is sorted from left to right.
- Each column is sorted from top to bottom.

👉 Start from the **top-right corner**.

At any position:

- If current element is greater than target, move left.
- If current element is smaller than target, move down.

This eliminates one row or one column in every step.

---

## Key Insight

Starting from top-right:

```text
Current > Target  → Move Left
Current < Target  → Move Down
Current == Target → Found
```

Why?

- Moving left gives smaller values.
- Moving down gives larger values.

---

## Approach

1. Initialize:
   - `row = 0`
   - `col = n - 1`

2. While inside matrix:
   - If current element equals target → return true
   - If current element is greater than target → move left
   - If current element is smaller than target → move down

3. If traversal ends → return false

---

## Complexity

- **Time:** `O(m + n)`
- **Space:** `O(1)`

where:

- `m` = number of rows
- `n` = number of columns

---

## Code

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0;
    int col = n - 1;

    while (row < m && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        }
        else if (target > matrix[row][col]) {
            row++;
        }
        else {
            col--;
        }
    }

    return false;
}
```

---

## Pattern

```text
Matrix Traversal
Staircase Search
```

---

## Common Mistakes

- Using `while(row <= col)` ❌
- Starting from top-left ❌
- Using nested loops `O(m*n)` ❌
- Forgetting matrix is sorted both row-wise and column-wise ❌

---

## Memory Trick

```text
Top Right

Too Big   → Left
Too Small → Down
Found     → Return
```

---

## Example

```text
1   4   7   11
2   5   8   12
3   6   9   16
```

Target = 8

```text
11 > 8 → Left
7  < 8 → Down
8  = 8 → Found
```
