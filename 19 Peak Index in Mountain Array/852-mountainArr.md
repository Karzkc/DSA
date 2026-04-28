https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

# Peak Index in a Mountain Array

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]

Output: 1
Example 3:
Input: arr = [0,10,5,2]

Output: 1
Constraints:
    3 <= arr.length <= 105
    0 <= arr[i] <= 106
    arr is guaranteed to be a mountain array.



## Intuition
The array first increases, reaches a peak, then decreases.  
We can use **binary search** to find the peak efficiently.

## Key Insight
At any index:
- If `arr[mid] < arr[mid+1]` → we are in the **increasing part** → peak is on the right.
- If `arr[mid] > arr[mid+1]` → we are in the **decreasing part** → peak is on the left or at mid.

## Approach
- Use binary search.
- Ignore first and last indices (they can’t be peak).
- At each step:
  - If `arr[mid]` is greater than both neighbors → return `mid`.
  - If left < mid → move right (`start = mid + 1`)
  - Else → move left (`end = mid - 1`)

## Complexity
- **Time:** `O(log n)`
- **Space:** `O(1)`

## Code
```cpp
int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    int i = 1, j = n - 2;

    while (i <= j) {
        int mid = i + (j - i) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) {
            return mid;
        }

        if (arr[mid - 1] < arr[mid]) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }

    return -1;
}
```
