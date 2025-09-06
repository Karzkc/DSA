#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortColors_brute(vector<int> &nums) // O(nlogn)
{
    sort(nums.begin(), nums.end());
}

void sortColors_optimized(vector<int> &nums) // O(n) 2Pass
{
    int n = nums.size();
    int zero = 0, one = 0, two = 0;
    for (auto &&i : nums)
    {
        if (i == 0)
        {
            zero++;
        }
        else if (i == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    int idx = 0;
    for (int i = 0; i < zero; i++)
    {
        nums[idx++] = 0;
    }
    for (int i = 0; i < one; i++)
    {
        nums[idx++] = 1;
    }
    for (int i = 0; i < two; i++)
    {
        nums[idx++] = 2;
    }
}

void sortColors_optimal(vector<int> &nums) // O(n) 1 Pass
{
    // Using DNS(Dutch National Flag) Algorithm

    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while (high >= mid)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) mid++;
        
        else if (nums[mid] == 2)
        {
            swap(nums[high], nums[mid]);
            high--;
        }
    }
}

int main()
{
    vector<int> vec = {2, 0, 2, 1, 1, 0};

    cout << "Older Array:" << endl;
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
    sortColors_optimal(vec);
    cout << "Sorted Array:" << endl;
    for (int num : vec)
    {
        cout << num << " ";
    }

    return 0;
}