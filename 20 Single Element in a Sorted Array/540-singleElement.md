https://leetcode.com/problems/single-element-in-a-sorted-array/description/

# Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

## Intuition

In a sorted array where every element appears twice except one:

- Pairs appear in order.
- Before the single element → pairs start at even index.
- After the single element → pairs shift and start at odd index.

We use **binary search** to detect where this pattern breaks.

## Key Insight

- For a correct pair:
  - First index = even
  - Second index = odd
- If this pattern breaks → the single element is on the left side.

## Approach

- Handle edge cases:
  - If only one element → return it.
  - If first element is unique → return `nums[0]`
  - If last element is unique → return `nums[n-1]`
- Use binary search:
  - If `nums[mid]` is not equal to both neighbors → return it.
  - If `mid` is even:
    - If `nums[mid] == nums[mid+1]` → move right
    - Else → move left
  - If `mid` is odd:
    - If `nums[mid] == nums[mid-1]` → move right
    - Else → move left

## Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`

## Code

```cpp
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int st = 0, end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Edge cases
        if (mid == 0 && nums[0] != nums[1]) return nums[0];
        if (mid == n - 1 && nums[n - 1] != nums[n - 2]) return nums[n - 1];

        // Check if mid is single
        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid + 1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        } else {
            if (nums[mid] == nums[mid - 1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}
```
