// https://leetcode.com/problems/4sum/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums)
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

        for (int j = i + 1; j < n;)
        {
            int a = j + 1, b = n - 1;

            while (a < b)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] +
                                (long long)nums[a] + (long long)nums[b];

                if (sum < 0)
                {
                    a++;
                }
                else if (sum > 0)
                {
                    b--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[a], nums[b]});
                    a++;
                    b--;
                    while (a < b && nums[a] == nums[a - 1])
                    {
                        a++;
                    }
                }
            }
            j++;
            while (j < n && nums[j] == nums[j - 1])
            {
                j++;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}