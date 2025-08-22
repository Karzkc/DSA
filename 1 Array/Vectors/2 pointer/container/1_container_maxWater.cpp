#include <iostream>
#include <vector>
using namespace std;


int maxArea(vector<int> &height)
{
    int area = 0;
    
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i+1; j < height.size(); j++)
        {
            area = max(area,(j-i)*min(height[i],height[j]));
        }
        
    }
    return area;
}

int main()
{
    vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(vec);
    return 0;
}

