/*
 * Function: maxSubArray
 * ---------------------
 * Implements Kadane's Algorithm to find the maximum sum of a contiguous subarray
 * within a given integer vector.
 *
 * Kadane's Algorithm Explanation:
 * - The algorithm iterates through the array, maintaining two variables:
 *   - cs (current sum): The sum of the current subarray being considered.
 *   - ms (maximum sum): The maximum subarray sum found so far.
 * - For each element, add it to cs.
 * - Update ms if cs is greater than ms.
 * - If cs becomes negative, reset cs to 0, as any subarray starting before this
 *   point would not contribute to a maximum sum in the future.
 * - This approach ensures O(n) time complexity and O(1) space complexity.
 *
 * Parameters:
 *   nums - Reference to a vector of integers representing the input array.
 *
 * Returns:
 *   The maximum sum of any contiguous subarray.
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int maxSubArray(vector<int> &nums)
{
    int cs = 0;
    int ms = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        cs += nums[i];
        ms = max(cs, ms);
        if (ms < 0)
        {
            cs = 0;
        }
    }
    return ms;
}

