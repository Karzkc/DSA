// https://leetcode.com/problems/sort-an-array/description/
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int quick(vector<int> &arr, int start, int end)
{
    int i = start - 1;
    int pivot = arr[end];
    for (int j = start; j < end ; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}
void quickSort(vector<int> &arr, int start, int end)
{

    if (start < end)
    {
        int pivotidx = quick(arr, start, end);
        quickSort(arr, start, pivotidx - 1);
        quickSort(arr, pivotidx + 1, end);
    }
}

vector<int> sortArray(vector<int> &arr)
{
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{

    return 0;
}