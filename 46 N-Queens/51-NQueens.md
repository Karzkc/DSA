https://leetcode.com/problems/n-queens/description/

# N-Queens

## Problem

The N-Queens puzzle is the problem of placing `n` queens on an `n × n` chessboard such that no two queens attack each other.

A queen can attack:

```text
Same Row
Same Column
Left Diagonal
Right Diagonal
```

Return all distinct solutions.

---

## Intuition

We need to place:

```text
1 Queen per Row
```

Instead of checking every cell on the board, process the board row by row.

For the current row:

```text
Try every column
Check if placement is valid
Place Queen
Move to next row
Backtrack
```

This naturally leads to a Backtracking solution.

---

## Key Observation

When placing queens row by row:

```text
Row 0
Row 1
Row 2
...
```

all rows below the current row are still empty.

Therefore, while checking validity, we only need to look:

```text
Up Column
Upper Left Diagonal
Upper Right Diagonal
```

No need to check downward directions.

---

## Validity Check

For position:

```cpp
(row, col)
```

Check:

### Same Column

```cpp
for (int i = 0; i < n; i++)
```

If another queen exists in the same column:

```text
Invalid
```

---

### Upper Left Diagonal

Move:

```text
row--
col--
```

until boundary is reached.

---

### Upper Right Diagonal

Move:

```text
row--
col++
```

until boundary is reached.

---

If no queen is found:

```text
Position is Safe
```

---

## Backtracking Approach

For every row:

### Try Every Column

```cpp
for(int col = 0; col < n; col++)
```

---

### If Safe

Place queen:

```cpp
board[row][col] = 'Q';
```

---

### Recurse

Move to the next row:

```cpp
getQueen(..., row + 1, ...);
```

---

### Backtrack

Remove queen:

```cpp
board[row][col] = '.';
```

This restores the board for the next choice.

---

## Base Case

When:

```cpp
row == n
```

all queens have been placed successfully.

Store the board:

```cpp
ans.push_back(board);
```

---

## Code

```cpp
bool isValid(vector<string>& board, int n, int row, int col)
{
    for (int j = 0; j < n; j++)
    {
        if (board[j][col] == 'Q')
        {
            return false;
        }
    }

    for (int i = row, j = col;
         i >= 0 && j >= 0;
         i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    for (int i = row, j = col;
         i >= 0 && j < n;
         i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void getQueen(vector<string>& board,
              int n,
              int row,
              vector<vector<string>>& ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isValid(board, n, row, col))
        {
            board[row][col] = 'Q';

            getQueen(board, n, row + 1, ans);

            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    vector<string> board(
        n,
        string(n, '.')
    );

    getQueen(board, n, 0, ans);

    return ans;
}
```

---

## Dry Run (n = 4)

Initial Board:

```text
....
....
....
....
```

Place Queen in:

```text
(0,0)
```

Board:

```text
Q...
....
....
....
```

Move to Row 1.

Try every column.

Only safe positions are explored.

Whenever a placement becomes invalid:

```text
Return
Backtrack
Try next column
```

When all 4 rows contain queens:

```text
Store Solution
```

---

## Complexity

### Time Complexity

For each row we try multiple columns.

Approximate complexity:

```text
O(N!)
```

because choices reduce as queens are placed.

---

### Space Complexity

Recursion stack:

```text
O(N)
```

Board storage:

```text
O(N²)
```

---

## Pattern

```text
Recursion
Backtracking
Constraint Satisfaction
```

---

## Common Mistakes

### Forgetting Backtracking

Wrong:

```cpp
board[row][col] = 'Q';
getQueen(...);
```

Without removing the queen afterwards.

---

### Missing Base Case

Must stop when:

```cpp
row == n
```

---

### Checking Entire Board

Unnecessary.

Only check:

```text
Column
Upper Left Diagonal
Upper Right Diagonal
```

because lower rows are empty.

---

## Memory Trick

```text
For Current Row:

Try Every Column

If Safe:
    Place Queen
    Recurse
    Remove Queen
```

Think:

```text
Place
Explore
Undo
```

This is the standard Backtracking pattern used in:

```text
Subsets
Permutations
N-Queens
Sudoku Solver
Word Search
```
