https://leetcode.com/problems/merge-sorted-array/

# Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


## Intuition
We are given two sorted arrays:
- `nums1` (size = m + n, with extra space at end)
- `nums2` (size = n)

👉 Instead of merging from front (which would overwrite values),  
we merge **from the back** to use empty space efficiently.

---

## Key Insight
- Start filling from the **end of nums1**
- Compare largest elements from both arrays
- Place the larger one at the end

👉 This avoids shifting elements and keeps it in-place

---

## Approach
1. Initialize pointers:
   - `i = m - 1` → last valid element in nums1  
   - `j = n - 1` → last element in nums2  
   - `idx = m + n - 1` → last position in nums1  

2. While both arrays have elements:
   - Compare `nums1[i]` and `nums2[j]`
   - Place larger at `nums1[idx]`
   - Move pointers accordingly  

3. If elements remain in `nums2`:
   - Copy them into nums1  

---

## Complexity
- **Time:** `O(m + n)`
- **Space:** `O(1)` (in-place)

---

## Code
```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, idx = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[idx--] = nums1[i--];
        } else {
            nums1[idx--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[idx--] = nums2[j--];
    }
}