https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

# Inversion Count (Merge Sort)

## Intuition

An inversion is a pair `(i, j)` such that:

- `i < j`
- `arr[i] > arr[j]`

Brute force checks every pair → **O(n²)**.

The trick is to count inversions **while merging** two already sorted halves.

---

## Key Observation

During merge:

```text
Left  = [1, 4, 7]
Right = [2, 5, 6]
```

If:

```cpp
left[i] > right[j]
```

then since the left half is sorted,

```text
left[i], left[i+1], ..., left[mid]
```

are **all greater** than `right[j]`.

So instead of counting one by one:

```cpp
count += mid - i + 1;
```

This is the entire trick of the problem.

---

## Approach

1. Divide array into two halves.
2. Recursively count inversions in left.
3. Recursively count inversions in right.
4. Count cross inversions during merge.
5. Return total.

---

## Why Merge Sort?

Merge Sort naturally gives us **two sorted halves**.

Without sorted halves, we can't conclude that all remaining elements on the left are also greater.

---

## Formula to Remember

Whenever:

```cpp
arr[i] > arr[j]
```

add

```cpp
mid - i + 1
```

Never count just `1`.

---

## Common Mistakes

❌ Copying back using:

```cpp
for(int i=0;i<arr.size();i++)
```

instead of

```cpp
for(int i=0;i<temp.size();i++)
```

Only the merged portion should be copied.

---

❌ Forgetting:

```cpp
mid - i + 1
```

and writing

```cpp
count++;
```

---

❌ Thinking every inversion is found separately.

One comparison can contribute **multiple inversions**.

---

## Complexity

- Time: **O(n log n)**
- Space: **O(n)**

---

## Pattern

Whenever a problem asks:

- Count pairs
- Count reverse pairs
- Count inversions
- Count smaller elements after self

Think:

> **Can Merge Sort count this during merge?**
