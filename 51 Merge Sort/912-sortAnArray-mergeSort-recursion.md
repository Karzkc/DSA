https://leetcode.com/problems/sort-an-array/

# Leetcode 912 - Sort an Array (Merge Sort)

## Problem

Given an integer array `nums`, sort the array in ascending order.

The expected optimal solution is **O(n log n)**.

---

# Why Merge Sort?

Merge Sort follows the **Divide and Conquer** paradigm.

It repeatedly:

1. Divide the array into two halves.
2. Sort both halves recursively.
3. Merge the two sorted halves.

---

# Intuition

Suppose:

```text
[5,2,3,1]
```

Split into two halves:

```text
[5,2]      [3,1]
```

Again split:

```text
[5] [2]    [3] [1]
```

Single elements are already sorted.

Now merge:

```text
[5] [2]
↓

[2,5]
```

```text
[3] [1]
↓

[1,3]
```

Finally merge:

```text
[2,5] + [1,3]

↓

[1,2,3,5]
```

---

# Divide and Conquer

```text
Array

↓

Divide

↓

Sort Left Half

↓

Sort Right Half

↓

Merge Both Halves
```

---

# Merge Function

Suppose:

```text
Left

[2,5]

Right

[1,3]
```

Compare:

```text
2 vs 1

↓

1
```

Compare:

```text
2 vs 3

↓

2
```

Compare:

```text
5 vs 3

↓

3
```

Remaining:

```text
5
```

Final merged array:

```text
[1,2,3,5]
```

---

# Algorithm

### Step 1

Find middle:

```cpp
int mid = start + (end - start) / 2;
```

---

### Step 2

Sort left half.

---

### Step 3

Sort right half.

---

### Step 4

Merge both sorted halves.

---

# Code

```cpp
void merge(vector<int>& arr, int start, int mid, int end)
{
    vector<int> temp;

    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= end)
        temp.push_back(arr[j++]);

    for (int i = 0; i < temp.size(); i++)
        arr[start + i] = temp[i];
}

void mergeSort(vector<int>& arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

vector<int> sortArray(vector<int>& arr)
{
    mergeSort(arr, 0, arr.size() - 1);
    return arr;
}
```

---

# Dry Run

Input:

```text
[5,2,3,1]
```

Split:

```text
[5,2] [3,1]
```

↓

```text
[5] [2]

↓

Merge

↓

[2,5]
```

↓

```text
[3] [1]

↓

Merge

↓

[1,3]
```

↓

Merge:

```text
[2,5]

[1,3]

↓

[1,2,3,5]
```

---

# Recursion Tree

```text
              [5,2,3,1]
             /          \
         [5,2]         [3,1]
        /    \         /    \
      [5]   [2]      [3]   [1]
        \    /         \    /
       [2,5]          [1,3]
            \          /
          [1,2,3,5]
```

---

# Complexity

### Time Complexity

```text
O(n log n)
```

Reason:

- `log n` levels of recursion.
- `O(n)` work at every level for merging.

---

### Space Complexity

```text
O(n)
```

Due to the temporary array used during merging.

---

# Why `start + (end - start) / 2`?

Instead of:

```cpp
(start + end) / 2
```

we use:

```cpp
start + (end - start) / 2
```

to prevent integer overflow when `start` and `end` are very large.

---

# Properties of Merge Sort

- Stable Sorting ✅
- Divide and Conquer ✅
- Recursive Algorithm ✅
- Worst Case: `O(n log n)` ✅
- Average Case: `O(n log n)` ✅
- Best Case: `O(n log n)` ✅
- Extra Space Required: `O(n)` ✅

---

# Pattern

```text
Divide

↓

Recursively Sort Left

↓

Recursively Sort Right

↓

Merge
```

---

# Memory Trick

```text
Divide

↓

Conquer

↓

Merge
```

Think:

```text
Break

↓

Sort

↓

Combine
```
