https://leetcode.com/problems/search-a-2d-matrix/

# Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m \* n)) time complexity.

## Intuition

The matrix has two important properties:

- Each row is sorted.
- The first element of a row is greater than the last element of the previous row.

👉 First find the correct row using Binary Search.

👉 Then perform Binary Search again inside that row.

---

## Key Insight

- The target can belong to only one row.
- Use row ranges:

  ```text
  matrix[row][0] <= target <= matrix[row][n-1]
  ```

Once the row is found, perform normal binary search on that row.

Approach
Step 1: Find the Row
Apply Binary Search on rows.

Check whether target lies between:

matrix[mid][0]
matrix[mid][n-1]
If yes, search inside that row.
Otherwise move left or right accordingly.
Step 2: Search in Row
Apply standard Binary Search on the selected row.
Return true if target found.
Otherwise return false.
Complexity
Time: O(log m + log n)
Space: O(1)

where:

m = number of rows
n = number of columns

## Code

```cpp
bool searchRow(vector<vector<int>> &matrix, int target, int row)
{
    int start = 0, end = matrix[row].size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (target < matrix[row][mid])
        {
            end = mid - 1;
        }
        else if (target > matrix[row][mid])
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int s = 0, e = m - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (target >= matrix[mid][0] &&
            target <= matrix[mid][n - 1])
        {
            return searchRow(matrix, target, mid);
        }
        else if (target > matrix[mid][n - 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return false;
}
```
