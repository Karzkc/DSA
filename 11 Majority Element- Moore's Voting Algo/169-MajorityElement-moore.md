https://leetcode.com/problems/majority-element/

# Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

## Brute ForceO(n²)

check all elements inside a loop if it matches ith element by using another loop - 

## Optimal - O(nlog)

firstly sort the array and check if elements are same or not , if same freq++ , else freq=1, and if freq=n/2 return element

# BEST - Moore's Voting Algo - O(n)
Moore's Voting Algorithm selects a candidate and increments/decrements a count based on matches. It resets the candidate when count reaches zero, ensuring the majority element is found in linear time.
If element is same as cuurent majority element , count increases otherwise decreases.

```
int majorityElement(vector<int> &nums) {
    int count = 0, major = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            major = nums[i];
            count = 1;
        } else if (nums[i] == major) {
            count++;
        } else {
            count--;
        }
    }
    return major;
}
```
