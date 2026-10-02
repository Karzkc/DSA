// https://leetcode.com/problems/sliding-window-maximum/description/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        ans.push_back(nums[dq.front()]);

        while (!dq.empty() && (i - k) >= dq.front())
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    ans.push_back(nums[dq.front()]);
    return ans;
}
// more optimal
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {

        while (!dq.empty() && (i - k) >= dq.front())
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main()
{

    return 0;
}