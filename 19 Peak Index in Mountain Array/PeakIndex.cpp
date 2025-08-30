#include <iostream>
#include <vector>
using namespace std;

    int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int i = 1, j = n - 2;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (arr[mid - 1] < arr[mid])
        {
            i = mid + 1;
        }
        else if (arr[mid - 1] > arr[mid])
        {
            j = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {0, 2, 1, 0};

    cout << peakIndexInMountainArray(vec);

    return 0;
}