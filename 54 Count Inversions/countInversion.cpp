// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int countInv = 0;

    int i = start, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
            countInv += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for (int k = 0; k < temp.size(); k++)
    {
        arr[k + start] = temp[k];
    }
    return countInv;
}

int mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        return mergeSort(arr, start, mid) + mergeSort(arr, mid + 1, end) + merge(arr, start, mid, end);
    }

    return 0;
}
int inversionCount(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}
int main()
{

    return 0;
}