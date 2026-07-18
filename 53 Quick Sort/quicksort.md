# Quick Sort

## Idea

Quick Sort is a **Divide and Conquer** algorithm.

Instead of dividing the array into equal halves like Merge Sort, it:

1. Chooses a **Pivot**.
2. Places the pivot in its correct sorted position.
3. Elements smaller than the pivot go to the left.
4. Elements greater than the pivot go to the right.
5. Recursively sort both halves.

---

# Partition

Suppose:

```text
[7,2,1,8,6,3,5,4]
```

Choose last element as pivot:

```text
Pivot = 4
```

Traverse the array.

Maintain:

```text
i -> last position of smaller element
j -> current element
```

Whenever:

```text
arr[j] <= pivot
```

Increase `i` and swap.

---

Example:

```text
Pivot = 4

[7,2,1,8,6,3,5,4]

↓

[2,1,3,4,6,8,5,7]
```

Now pivot is in its correct position.

Everything left:

```text
<= 4
```

Everything right:

```text
> 4
```

---

# Algorithm

```text
Choose Pivot

↓

Partition Array

↓

Pivot reaches correct position

↓

Recursively sort Left

↓

Recursively sort Right
```

---

# Code

```cpp
int partition(vector<int>& arr, int start, int end)
{
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[end]);

    return i;
}

void quickSort(vector<int>& arr, int start, int end)
{
    if (start >= end)
        return;

    int pivotIdx = partition(arr, start, end);

    quickSort(arr, start, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, end);
}

vector<int> sortArray(vector<int>& arr)
{
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}
```

---

# Dry Run

Input:

```text
[4,1,7,3,2]
```

Pivot:

```text
2
```

Partition:

```text
[1,2,7,3,4]
```

Pivot index:

```text
1
```

Now sort:

```text
Left:

[1]

Right:

[7,3,4]
```

Continue recursively.

Final:

```text
[1,2,3,4,7]
```

---

# Recursion Tree

```text
                Array
                  |
             Partition
            /         \
       Left Half    Right Half
          |             |
     Partition      Partition
          |             |
        ...           ...
```

---

# Complexity

### Best Case

```text
O(n log n)
```

Balanced partitions.

---

### Average Case

```text
O(n log n)
```

---

### Worst Case

```text
O(n²)
```

Occurs when partitions become highly unbalanced.

Example:

```text
Already Sorted

[1,2,3,4,5]
```

Using last element as pivot:

```text
Left : n-1 elements

Right : 0 elements
```

Recursion becomes:

```text
n

↓

n-1

↓

n-2

↓

...

↓

1
```

Hence:

```text
O(n²)
```

---

# Space Complexity

Average:

```text
O(log n)
```

Worst:

```text
O(n)
```

due to recursion stack.

---

# Why Leetcode 912 Gives TLE?

Using:

```cpp
pivot = arr[end];
```

can produce the worst-case recursion for already sorted or specially crafted inputs.

Leetcode includes such test cases intentionally.

Therefore, although the implementation is correct, it may result in **Time Limit Exceeded**.

Solutions that always pass include:

- Merge Sort
- Heap Sort
- `std::sort()` (Introsort)

---

# Small Optimization

Instead of:

```cpp
if (start >= end)
{
    return;
}

if (start < end)
{
    ...
}
```

Use only:

```cpp
if (start >= end)
    return;

int pivotIdx = partition(arr, start, end);

quickSort(arr, start, pivotIdx - 1);
quickSort(arr, pivotIdx + 1, end);
```

The second `if` is unnecessary.

---

# Merge Sort vs Quick Sort

| Merge Sort             | Quick Sort                         |
| ---------------------- | ---------------------------------- |
| Divide into halves     | Partition around pivot             |
| Stable                 | Not Stable                         |
| O(n log n) worst case  | O(n²) worst case                   |
| O(n) extra space       | O(log n) recursion space (average) |
| Guaranteed performance | Usually faster in practice         |

---

# Pattern

```text
Choose Pivot

↓

Partition

↓

Recursively Sort Left

↓

Recursively Sort Right
```

---

# Memory Trick

```text
Pivot

↓

Partition

↓

Left

Right

↓

Repeat
```

Think:

```text
Choose

Split

Sort
```
