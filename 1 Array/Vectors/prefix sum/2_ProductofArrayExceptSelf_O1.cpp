#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int suffix = 1;
    vector<int> ans(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(vec);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}