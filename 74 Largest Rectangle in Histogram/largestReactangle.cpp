#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    heights.push_back(0);
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int height = heights[st.top()];
            st.pop();

            int width;

            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }

    return maxArea;
}

int main()
{

    return 0;
}