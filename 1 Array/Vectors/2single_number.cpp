#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> vec)
{
    cout << "Your arr is:" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "Element " << i << " : " << vec[i] << endl;
    }
}

int singleNumber(vector<int> &nums)
{
    int x = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        x^=nums[i];
    }
    return x;
    
}

int main()
{
    vector<int> vec = {2,2,1};

    cout << "original array:" << endl;
    display(vec);
    singleNumber(vec);
    return 0;
}