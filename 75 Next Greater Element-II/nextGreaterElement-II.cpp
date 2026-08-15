// https://leetcode.com/problems/next-greater-element-ii/description/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> s;
    int n = nums.size();
    vector<int> ans(n, 0);

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int idx = i % n;
        while (!s.empty() && nums[s.top()] <= nums[idx])
        {
            s.pop();
        }
        ans[idx] = s.empty() ? -1 : nums[s.top()];
        s.push(idx);
    }
    return ans;
}

int main()
{

    return 0;
}