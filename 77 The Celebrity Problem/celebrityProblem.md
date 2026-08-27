https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

# GFG - The Celebrity Problem

## Intuition

A celebrity has two properties:

1. **Everyone knows the celebrity.**
2. **Celebrity knows nobody.**

Instead of checking every person against everyone else, eliminate people who **cannot possibly be the celebrity**.

---

## Approach: Stack Elimination

Initially, put everyone into the stack:

```text
[0, 1, 2, 3, ...]
```

Take two people at a time:

```cpp
i = s.top();
j = s.top();
```

Ask:

```cpp
mat[i][j]
```

### If `i` knows `j`

```text
i → j
```

Then `i` **cannot** be the celebrity because a celebrity knows nobody.

So:

```cpp
s.push(j);
```

### If `i` does NOT know `j`

```text
i ✗→ j
```

Then `j` **cannot** be the celebrity because everyone must know the celebrity.

So:

```cpp
s.push(i);
```

Thus, every comparison eliminates one person.

---

## Example

Suppose we compare:

```text
i = 2
j = 4
```

If:

```cpp
mat[2][4] == 1
```

then:

```text
2 knows 4
```

Therefore `2` cannot be celebrity.

Keep `4`.

```text
2 ❌
4 ✓ candidate
```

Continue until only one candidate remains.

---

## Important: Candidate ≠ Celebrity

After elimination, the remaining person is only a **candidate**.

They still need to be verified.

For candidate `celeb`, check every person `i`:

### Everyone must know celebrity

```cpp
mat[i][celeb] == 1
```

### Celebrity must know nobody

```cpp
mat[celeb][i] == 0
```

So:

```cpp
if (i != celeb &&
    (mat[i][celeb] == 0 || mat[celeb][i] == 1))
{
    return -1;
}
```

If all checks pass:

```cpp
return celeb;
```

---

## Key Insight

The elimination works because every comparison guarantees that **one of the two people cannot be the celebrity**.

```text
i knows j
    ↓
i eliminated

i doesn't know j
    ↓
j eliminated
```

So `n` people become one candidate in `n - 1` comparisons.

---

## Common Mistakes

- Assuming the final stack element is automatically the celebrity.
- Forgetting the final verification.
- Reversing the elimination logic.
- Checking only "everyone knows candidate" but forgetting that the candidate must know nobody.
- Forgetting `i != celeb` during verification.

---

## Complexity

### Stack approach

- Candidate elimination: `O(n)`
- Candidate verification: `O(n)`
- **Total Time:** `O(n)`
- **Space:** `O(n)`

---

## Pattern Learned

### Elimination / Candidate Reduction

When a problem asks you to find one special element among many, ask:

> **Can I prove that one of two candidates cannot be the answer?**

If yes, eliminate one at every comparison.

For the Celebrity Problem:

```text
n candidates
    ↓
pairwise elimination
    ↓
1 candidate
    ↓
verify candidate
    ↓
Celebrity / -1
```

The important idea is **eliminate first, verify later**.
