#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums){
    int summax= INT16_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int sumnow = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sumnow +=nums[j];
            summax+=max(summax,sumnow);
        }
        
    }
    
}

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    cout << "Vector elements: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}