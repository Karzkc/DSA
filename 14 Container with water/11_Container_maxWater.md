https://leetcode.com/problems/container-with-most-water/description/

# Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
![alt text](image.png)
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1

Constraints:
n == height.length
2 <= n <= 105
0 <= height[i] <= 104

## Brute Force - O(n²)

Loop through all combinations of left and right boundaries to find the maximum area.

## Best Approach - Two Pointers

- Use two pointers: `i = 0` and `j = height.size() - 1`
- Track the maximum area found so far
- Move the pointer pointing to the shorter height inward (this optimizes by eliminating cases that can't yield larger areas)

### Code

```cpp
int maxArea(vector<int>& height) {
    int area = 0;
    int i = 0;
    int j = height.size() - 1;

    while (i < j) {
        area = max(area, (j - i) * min(height[i], height[j]));
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return area;
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)
