#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int area = 0, i = 0, j = height.size() - 1;
    while (i<j)
    {
        area = max(area,(j-i)*min(height[i],height[j]));
        if (height[j]>height[i])
        {
            i++;
        }
        else
        {
            j--;
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