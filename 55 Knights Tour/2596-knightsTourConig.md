https://leetcode.com/problems/check-knight-tour-configuration/description/

# LC 2596 - Check Knight Tour Configuration

## Intuition

The grid already contains the knight's tour.

We are **not generating** the tour.

We only need to verify:

> Can a knight move from `0 → 1 → 2 → ... → n²-1`?

Think of it as following a path.

---

## Approach

Start from:

```text
0
```

For every current value:

1. Verify the current cell contains `nextVal`.
2. Try all 8 possible knight moves.
3. Recurse with `nextVal + 1`.
4. If any path reaches `n² - 1`, the tour is valid.

---

## Knight Moves

```text
(+1, -2)
(+2, -1)
(+2, +1)
(+1, +2)

(-1, +2)
(-2, +1)
(-2, -1)
(-1, -2)
```

A knight always moves:

- 2 in one direction
- 1 in the perpendicular direction

---

## Why No Visited Array?

Every number from `0` to `n²-1` appears exactly once in the grid.

We're simply checking whether the next number exists at a valid knight position.

We're **not exploring different paths** like N-Queens or Sudoku.

---

## Base Case

```cpp
if(nextVal == n*n - 1)
    return true;
```

Reaching the last number means the entire tour is valid.

---

## Common Mistakes

❌ Forgetting to check boundaries.

❌ Starting from a cell other than `(0,0)`.

❌ Thinking this is a backtracking problem.

There is **no state to undo**, so no backtracking is required.

---

## Complexity

- Time: **O(8 × n²) ≈ O(n²)**
- Space: **O(n²)** (recursion depth in the worst case)

---

## Pattern

Whenever a problem gives:

- A fixed sequence
- Need to verify if each next state is reachable

Think:

> **DFS / Recursion for validation**, not backtracking.

---

## Better Approach (Interview)

A more efficient solution is to first store the position of every value:

```text
position[value] = (row, col)
```

Then simply check whether every consecutive pair:

```text
0 → 1
1 → 2
2 → 3
...
```

forms a valid knight move.

- Time: **O(n²)**
- No recursion
- Easier to reason about
