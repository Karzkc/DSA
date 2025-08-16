#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>nums){
    int maxsum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {   
        for (int j = i; j< nums.size(); j++)
        {
            int max = 0;
            for (int k = i; k<=j; k++)
            {
                max+=nums[k];
                
            }
            maxsum = std::max(maxsum, max);
            
        }
    }
    return maxsum;
}

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    maxSubArray(vec);

    return 0;
}