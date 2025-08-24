#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bsr(vector<int> nums, int target, int st, int end)
{
    sort(nums.begin(), nums.end());
    int mid = st + (-st + end) / 2;
    if (target < nums[mid])
    {
        return bsr(nums, target, st, mid - 1);
    }
    else if (target > nums[mid])
    {
        return bsr(nums, target, mid + 1, end);
    }
    else
    {
        return mid;
    }

    return -1;
}

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};

    cout << bsr(vec, 50,0,vec.size()-1);

    return 0;
}