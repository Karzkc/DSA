// https://www.geeksforgeeks.org/problems/previous-smaller-element/1
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> prevSmaller(vector<int> nums)
{
    vector<int> ans(nums.size(), 0);
    stack<int> s;

    for (int i = 0; i < nums.size(); i++)
    {
        while (!s.empty() && s.top() >= nums[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }

        s.push(nums[i]);
    }
    return ans;
}
int main()
{

    return 0;
}