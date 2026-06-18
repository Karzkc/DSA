// https://leetcode.com/problems/subarray-sum-equals-k/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> psum(n, 0);
    psum[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        psum[i] = psum[i - 1] + nums[i];
    }

    int count = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        if (psum[i] == k)
        {
            count++;
        }

        int val = psum[i] - k;

        if (m.find(val) != m.end())
        {
            count += m[val];
        }
        if (m.find(psum[i]) == m.end())
        {
            m[psum[i]] = 0;
        }

        m[psum[i]]++;
    }
    return count;
}

int main()
{

    return 0;
}