// https://leetcode.com/problems/trapping-rain-water/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    left[0] = height[0];
    right[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - height[i];
    }
    return ans;
}
int trap_optimal(vector<int> &height)
{
    int n = height.size();
    int ans = 0;
    int i = 0, j = n - 1;
    int left = 0, right = 0;

    while (i < j)
    {
        left = max(left, height[i]);
        right = max(right, height[j]);

        if (left < right)
        {
            ans += left - height[i++];
        }
        else
        {
            ans += right - height[j--];
        }
    }
    return ans;
}
int main()
{

    return 0;
}