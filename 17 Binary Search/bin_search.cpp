#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> nums, int target)
{
    sort(nums.begin(),nums.end());
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (target < nums[mid])
        {
            end = mid - 1;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};

    cout << binary_search(vec, 50);

    return 0;
}