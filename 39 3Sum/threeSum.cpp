// https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
vector<vector<int>> threeSumBrute(vector<int> &nums) // TLE
{
    int n = nums.size();
    set<vector<int>> s;
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    if (s.find(triplet) == s.end())
                    {
                        s.insert(triplet);
                        ans.push_back(triplet);
                    }
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> threeSumBetter(vector<int> &nums) // TLE
{
    int n = nums.size();
    set<vector<int>> uniquetrip;

    for (int i = 0; i < n; i++)
    {
        int target = -nums[i];
        set<int> s;
        for (int j = i + 1; j < n; j++)
        {
            int third = target - nums[j];

            if (s.find(third) != s.end())
            {
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end());
                uniquetrip.insert(triplet);
            }
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(uniquetrip.begin(), uniquetrip.end());
    return ans;
}
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }

    return ans;
}
int main()
{

    return 0;
}