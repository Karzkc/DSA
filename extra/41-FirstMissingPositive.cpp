// https://leetcode.com/problems/first-missing-positive/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= 0 || nums[i] > n)
        {
            nums[i] = n + 1;
        }
      
    }

    for (int i = 0; i < n; i++)
    {

        if (nums[i] == n + 1)
        {
            continue;
        }
        int idx = nums[i] - 1;
        if (nums[idx] > 0)
        {
            nums[idx] = -nums[idx];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            return nums[i];
        }
        else
        {
            return n + 1;
        }
    }
}
int main()
{

    return 0;
}