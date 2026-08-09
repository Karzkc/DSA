// https://leetcode.com/problems/next-greater-element-i/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> s;
    unordered_map<int, int> m;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {

        while (!s.empty() && s.top() <= nums2[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            m[nums2[i]] = -1;
        }
        else
        {
            m[nums2[i]] = s.top();
        }
        s.push(nums2[i]);
    }
    vector<int> res;

    for (int i = 0; i < nums1.size(); i++)
    {
        res.push_back(m[nums1[i]]);
    }
    return res;
}

int main()
{

    return 0;
}