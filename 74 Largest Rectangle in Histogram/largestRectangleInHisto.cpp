// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    vector<int> right(n, 0);
    vector<int> left(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;
        area = max(area, (width * heights[i]));
    }
    return area;
}

int main()
{

    return 0;
}