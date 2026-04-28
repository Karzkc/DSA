https://leetcode.com/problems/product-of-array-except-self/

# Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

## Brute Force - O(n²)

Use nested loops to calculate the product of all elements except the current one.
## Optimal Approach 1 - O(n) Time, O(n) Space

Use prefix and suffix arrays:

- **Prefix array**: product of all elements before index i
- **Suffix array**: product of all elements after index i
- **Result**: prefix[i] × suffix[i]

```cpp
vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> prefix(nums.size(), 1);
    vector<int> suffix(nums.size(), 1);
    vector<int> ans(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++)
        prefix[i] = prefix[i - 1] * nums[i - 1];

    for (int i = nums.size() - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] * nums[i + 1];

    for (int i = 0; i < nums.size(); i++)
        ans[i] = prefix[i] * suffix[i];

    return ans;
}
```

## Optimal Approach 2 - O(n) Time, O(1) Space

Store prefix in the result array and compute suffix on-the-fly:

```cpp
vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> ans(nums.size(), 1);
    int suffix = 1;

    for (int i = 1; i < nums.size(); i++)
        ans[i] = ans[i - 1] * nums[i - 1];

    for (int i = nums.size() - 2; i >= 0; i--) {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}
```
