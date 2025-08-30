#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> merged = nums1;
    
    merged.insert(merged.end(), nums2.begin(), nums2.end());
    sort(merged.begin(), merged.end());
    int n = merged.size();

    if (n % 2 != 0)
    {
        return merged[n/2];
    }
    else
    {
        return (merged[n / 2] + merged[(n / 2) - 1]) / 2.0;
    }
}