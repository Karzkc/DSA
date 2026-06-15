https://leetcode.com/problems/find-missing-and-repeated-values/description/

# Find Missing and Repeated Values

## Intuition

The grid contains numbers from:

```text
1 to n²
```

Exactly:

- One number is missing.
- One number appears twice.

👉 While traversing the grid:

- Use an `unordered_set` to detect the repeated number.
- Compute the actual sum of all elements.
- Compare it with the expected sum of numbers from `1` to `n²`.

---

## Key Insight

Let:

```text
repeated = x
missing = y
```

Expected sum:

```text
1 + 2 + ... + n²
```

Formula:

```text
N(N+1)/2
```

where:

```text
N = n²
```

Since:

```text
actualSum = expectedSum + repeated - missing
```

We get:

```text
missing = expectedSum - actualSum + repeated
```

---

## Approach

1. Calculate:

```cpp
N = n * n
```

2. Find expected sum:

```cpp
N * (N + 1) / 2
```

3. Traverse matrix:
   - Add elements to actual sum.
   - Use `unordered_set` to detect repeated value.

4. Compute missing value:

```cpp
missing = expectedSum - actualSum + repeated
```

5. Return:

```cpp
{repeated, missing}
```

---

## Complexity

- **Time:** `O(n²)`
- **Space:** `O(n²)`

---

## Code

```cpp
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

    int n = grid.size();

    long long N = 1LL * n * n;

    long long expectedSum = N * (N + 1) / 2;

    long long actualSum = 0;

    int repeated = -1;

    unordered_set<int> seen;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            int num = grid[i][j];

            actualSum += num;

            if (seen.count(num)) {
                repeated = num;
            }

            seen.insert(num);
        }
    }

    int missing = expectedSum - actualSum + repeated;

    return {repeated, missing};
}
```

---

## Example

Input:

```text
1 3
2 2
```

Numbers should be:

```text
1 2 3 4
```

Expected Sum:

```text
10
```

Actual Sum:

```text
8
```

Repeated:

```text
2
```

Missing:

```text
10 - 8 + 2 = 4
```

Answer:

```text
[2,4]
```

---

## Pattern

```text
Hash Set
Math (Expected Sum)
```

---

## Common Mistakes

- Using sum formula for `1...n` instead of `1...n²` ❌
- Returning `{missing, repeated}` instead of `{repeated, missing}` ❌
- Using `int` for large sums ❌
- Forgetting to store visited numbers in the set ❌

---

## Memory Trick

```text
Find duplicate using Set

Expected Sum - Actual Sum
        +
   Repeated Number

= Missing Number
```
