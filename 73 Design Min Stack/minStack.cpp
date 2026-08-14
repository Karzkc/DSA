#include <stack>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

class MinStack_I
{
    stack<pair<int, int>> s;

public:
    MinStack_I() {}

    void push(int value)
    {
        if (s.empty())
        {
            s.push({value, value});
        }
        else
        {
            int minVal = min(value, s.top().second);
            s.push({value, minVal});
        }
    }

    void pop() { s.pop(); }

    int top() { return s.top().first; }

    int getMin() { return s.top().second; }
};

class MinStack_II
{
    stack<long long int> s;
    long long int minVal = INT32_MAX;

public:
    MinStack_II() {}

    void push(int value)
    {
        if (s.empty())
        {
            s.push(value);
            minVal = value;
        }
        else
        {
            if (value < minVal)
            {
                s.push((long long)2 * value - minVal);
                minVal = value;
            }
            else
            {
                s.push(value);
            }
        }
    }

    void pop()
    {
        if (s.top() < minVal)
        {
            minVal = 2 * minVal - s.top();
        }

        s.pop();
    }

    int top()
    {
        if (s.top() < minVal)
        {
            return minVal;
        }
        else
        {
            return s.top();
        }
    }

    int getMin() { return minVal; }
};

int main()
{

    return 0;
}