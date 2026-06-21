#include <iostream>
#include <vector>
using namespace std;

void getSubsets(vector<int> &arr, vector<vector<int>> &ans, vector<int> &curr, int i)
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
    getSubsets(arr, ans, curr, i + 1);
}
vector<vector<int>> subsets(vector<int> &arr)
{
    vector<int> curr;
    vector<vector<int>> ans;
    getSubsets(arr, ans, curr, 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
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