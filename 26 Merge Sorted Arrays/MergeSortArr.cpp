#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int i = m - 1, idx = n + m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] <= nums2[j])
        {
            nums1[idx--] = nums2[j--];
        }
        else
        {
            nums1[idx--] = nums1[i--];
        }
    }
    while (j >= 0)
    {
        nums1[idx--] = nums2[j--];
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    cout << "Nums1:" << endl;
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "Nums2:" << endl;
    for (int num : nums2)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "Merged:" << endl;
    merge(nums1, n, nums2, m);
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}