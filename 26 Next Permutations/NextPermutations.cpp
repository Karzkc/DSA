// https://leetcode.com/problems/next-permutation/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    int rme = 0;
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            rme = i;
            break;
        }
    }

    swap(nums[pivot], nums[rme]);

    reverse(nums.begin() + pivot + 1, nums.end());
}

int main()
{
    vector<int> vec = {1, 2, 3};

    cout << "Your array: " << endl;
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
    nextPermutation(vec);
    cout << "Next lexicographical array:" << endl;
    for (int num : vec)
    {
        cout << num << " ";
    }

    return 0;
}