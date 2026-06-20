#include <iostream>
#include <vector>
using namespace std;

int binSearchRec(vector<int> arr, int start, int end, int target)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;
    else if (target > arr[mid])
    {
        return binSearchRec(arr, mid + 1, end, target);
    }
    else
    {
        return binSearchRec(arr, start, mid - 1, target);
    }
}

int search(vector<int> nums, int target)
{
    return binSearchRec(nums, 0, nums.size() - 1, target);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << search(arr, 4);
    return 0;
}