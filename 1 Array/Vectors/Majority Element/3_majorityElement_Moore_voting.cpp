#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> &nums) {
    int count = 0, major = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            major = nums[i];
            count = 1;
        } else if (nums[i] == major) {
            count++;
        } else {
            count--;
        }
    }
    return major;
}


int main()
{
    vector<int> vec = {3, 2, 3};
    cout << majorityElement(vec);

    return 0;
}