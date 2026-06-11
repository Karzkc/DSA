https://leetcode.com/problems/spiral-matrix/

# Spiral Matrix

## Intuition

We need to traverse the matrix in spiral order:

```text
→ Right
↓ Down
← Left
↑ Up
```

After completing one layer, move inward and repeat.

---

## Key Insight

Maintain four boundaries:

```cpp
srow = top row
erow = bottom row

scol = left column
ecol = right column
```

After traversing one side, shrink the corresponding boundary.

---

## Approach

### 1. Traverse Top Row

```text
left → right
```

Then:

```cpp
srow++;
```

---

### 2. Traverse Right Column

```text
top → bottom
```

Then:

```cpp
ecol--;
```

---

### 3. Traverse Bottom Row

```text
right → left
```

Only if:

```cpp
srow <= erow
```

Then:

```cpp
erow--;
```

---

### 4. Traverse Left Column

```text
bottom → top
```

Only if:

```cpp
scol <= ecol
```

Then:

```cpp
scol++;
```

---

### 5. Repeat

Continue until:

```cpp
srow > erow
```

or

```cpp
scol > ecol
```

---

## Why Are The IF Conditions Needed?

Consider:

```text
1 2 3
```

After traversing the top row:

```cpp
srow++;
```

Now:

```text
srow > erow
```

There is no bottom row left.

Without:

```cpp
if (srow <= erow)
```

the bottom row would be traversed again, causing duplicates.

Same logic applies to:

```cpp
if (scol <= ecol)
```

for the left column.

---

## Complexity

- **Time:** `O(m × n)`
- **Space:** `O(1)` (excluding answer array)

---

## Code

```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> spiral;

    int m = matrix.size();
    int n = matrix[0].size();

    int srow = 0, erow = m - 1;
    int scol = 0, ecol = n - 1;

    while (srow <= erow && scol <= ecol) {

        // Top Row
        for (int i = scol; i <= ecol; i++) {
            spiral.push_back(matrix[srow][i]);
        }
        srow++;

        // Right Column
        for (int i = srow; i <= erow; i++) {
            spiral.push_back(matrix[i][ecol]);
        }
        ecol--;

        // Bottom Row
        if (srow <= erow) {
            for (int i = ecol; i >= scol; i--) {
                spiral.push_back(matrix[erow][i]);
            }
            erow--;
        }

        // Left Column
        if (scol <= ecol) {
            for (int i = erow; i >= srow; i--) {
                spiral.push_back(matrix[i][scol]);
            }
            scol++;
        }
    }

    return spiral;
}
```

---

## Pattern

```text
Matrix Traversal
Boundary Shrinking
Simulation
```

---

## Common Mistakes

- Forgetting:

  ```cpp
  if (srow <= erow)
  ```

  before bottom row ❌

- Forgetting:

  ```cpp
  if (scol <= ecol)
  ```

  before left column ❌

- Updating boundaries incorrectly ❌



---

## Memory Trick

```text
Top Row
Right Column
Bottom Row
Left Column

Shrink Boundaries

Repeat
```

Or simply:

```text
Right → Down → Left → Up
Move inward
```
