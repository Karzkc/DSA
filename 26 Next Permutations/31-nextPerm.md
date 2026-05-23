https://leetcode.com/problems/next-permutation/

# Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

    For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

    For example, the next permutation of arr = [1,2,3] is [1,3,2].
    Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
    While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]

## Intuition

We need to generate the **next lexicographically greater permutation** of the array.

👉 If not possible (array is in descending order), return the **smallest permutation (sorted ascending)**.

---

## Key Insight

- Traverse from right and find the first index where:

```nums[i] < nums[i + 1]```

→ this is the **pivot (dip point)**

- After pivot:
- Find the **just greater element** on the right
- Swap them
- Reverse the right part to get smallest order

---

## Approach

1. Find pivot:

- Traverse from right
- First `i` such that `nums[i] < nums[i+1]`

2. If no pivot found:

- Reverse entire array

3. Else:

- Find element greater than `nums[pivot]` from right
- Swap them

4. Reverse subarray from `pivot+1` to end

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

---

## Code

```cpp
void nextPermutation(vector<int>& nums) {
  int n = nums.size();
  int pivot = -1;

  // Step 1: find pivot
  for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
          pivot = i;
          break;
      }
  }

  // Step 2: if no pivot, reverse whole array
  if (pivot == -1) {
      reverse(nums.begin(), nums.end());
      return;
  }

  // Step 3: find next greater element
  for (int i = n - 1; i > pivot; i--) {
      if (nums[i] > nums[pivot]) {
          swap(nums[i], nums[pivot]);
          break;
      }
  }

  // Step 4: reverse suffix
  reverse(nums.begin() + pivot + 1, nums.end());
}
```
