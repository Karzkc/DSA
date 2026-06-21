// https://leetcode.com/problems/subsets-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getSubsets(vector<int> &arr, vector<vector<int>> &ans,
                vector<int> &curr, int i)
{
    if (i == arr.size())
    {
        ans.push_back(curr);
        return;
    }

    // include
    curr.push_back(arr[i]);
    getSubsets(arr, ans, curr, i + 1);

    // exclude
    curr.pop_back();

    // duplciate logic
    int idx = i + 1;
    while (idx < arr.size() && arr[idx] == arr[idx - 1])
    {
        idx++;
    }

    getSubsets(arr, ans, curr, idx);
}
vector<vector<int>> subsets(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> curr;
    vector<vector<int>> ans;
    getSubsets(arr, ans, curr, 0);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsets(nums);
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}