// https://leetcode.com/problems/sort-an-array/description/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;
    // first while for comapring both arrays's elemets
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    // second and third while for remaining i and j elements

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + start] = temp[i];
    }
}
void mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
vector<int> sortArray(vector<int> &arr)
{
    mergeSort(arr, 0, arr.size() - 1);
    return arr;
}
int main()
{

    return 0;
}