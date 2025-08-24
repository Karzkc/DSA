#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[start] <= nums[mid])
        {
            if (target >= nums[start] && target <= nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        else
        {
            if (target >= nums[mid + 1] && target <= nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};

    cout << search(vec, 50);

    return 0;
}