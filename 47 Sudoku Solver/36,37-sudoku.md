https://leetcode.com/problems/sudoku-solver/description/
https://leetcode.com/problems/valid-sudoku/

# Sudoku (Leetcode 36 & 37)

Both problems revolve around the same core idea:

```text
A digit is valid if it does not already exist in:

1. Same Row
2. Same Column
3. Same 3×3 Box
```

The difference is:

- **Leetcode 36** only checks whether the current board is valid.
- **Leetcode 37** uses Backtracking to fill the empty cells.

---

# Leetcode 36 - Valid Sudoku

## Problem

Determine whether a partially filled Sudoku board is valid.

Rules:

- No duplicate digit in any row.
- No duplicate digit in any column.
- No duplicate digit in any 3×3 sub-box.

Only filled cells need to be validated.

---

## Intuition

Traverse every cell.

For every non-empty cell:

- Check Row
- Check Column
- Check 3×3 Box

If any duplicate exists:

```cpp
return false;
```

Otherwise:

```cpp
return true;
```

---

## 3×3 Box Trick

For a cell:

```cpp
(row, col)
```

The starting position of its box is:

```cpp
startRow = row - row % 3;
startCol = col - col % 3;
```

Equivalent formula:

```cpp
startRow = (row / 3) * 3;
startCol = (col / 3) * 3;
```

Then iterate:

```cpp
startRow -> startRow + 2
startCol -> startCol + 2
```

---

## Approach

```
Traverse entire board

↓

Ignore '.'

↓

Validate current digit

↓

If invalid

Return false

↓

After checking all cells

Return true
```

---

## Time Complexity

```
O(81 × 27)

≈ O(1)
```

Since Sudoku board size is fixed.

---

## Pattern

```
Matrix Traversal
Validation
```

---

# Leetcode 37 - Sudoku Solver

## Problem

Fill the Sudoku board so that every empty cell contains a valid digit.

The board is guaranteed to have one unique solution.

---

## Intuition

Instead of checking the board,

now we **fill** the board.

Whenever we find an empty cell:

Try every digit:

```text
1
2
3
...
9
```

If placing a digit is valid:

- Place it
- Solve remaining board recursively

If it fails:

- Remove it
- Try another digit

This is classic Backtracking.

---

## Relationship with Problem 36

Leetcode 36 already gave us:

```cpp
isValid()
```

Leetcode 37 simply reuses it.

Only the recursion is new.

---

## Backtracking Logic

Find first empty cell:

```
'.'
```

↓

Try digits:

```
'1' -> '9'
```

↓

If valid:

```
Place Digit
```

↓

Recursive Call

↓

If solved:

```
Return true
```

↓

Otherwise

```
Remove Digit
```

↓

Try next digit

---

## Base Case

When recursion reaches beyond the last row:

```
Entire board filled
```

Return:

```cpp
true;
```

---

## Recursive Flow

```
Find Empty Cell

↓

Try 1..9

↓

Valid ?

↓

Yes

↓

Place Digit

↓

Recurse

↓

Solved ?

↓

Yes -> Return true

↓

No

↓

Remove Digit

↓

Try Next Digit
```

---

## Why Backtracking?

Suppose:

```
Cell (3,4)
```

Place:

```
'5'
```

Later recursion fails.

That means:

```
'5'
```

was the wrong choice.

Undo it:

```cpp
board[row][col] = '.';
```

Then try:

```
'6'
```

This is Backtracking.

---

## Time Complexity

Worst Case:

```
O(9^(empty cells))
```

Although in practice it is much faster because invalid branches are pruned early.

---

## Pattern

```
Recursion
Backtracking
Constraint Satisfaction
```

---

# Common `isValid()` Logic

For a digit at:

```cpp
(row, col)
```

Check:

### Row

```
No duplicate digit
```

### Column

```
No duplicate digit
```

### 3×3 Box

```
No duplicate digit
```

If all pass:

```cpp
return true;
```

Otherwise:

```cpp
return false;
```

---

# Difference Between 36 and 37

| Leetcode 36           | Leetcode 37    |
| --------------------- | -------------- |
| Validate board        | Solve board    |
| No Recursion          | Recursion      |
| No Backtracking       | Backtracking   |
| Check existing digits | Try digits 1–9 |
| Return bool           | Modify board   |

---

# Memory Trick

### Valid Sudoku

```
Traverse

↓

Check

↓

Return
```

### Sudoku Solver

```
Find Empty Cell

↓

Try Digit

↓

Check

↓

Place

↓

Recurse

↓

Undo
```

Think:

```
Validate

↓

Choose

↓

Explore

↓

Undo
```

This is the same Backtracking pattern used in:

- Subsets
- Permutations
- N-Queens
- Sudoku Solver
