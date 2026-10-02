// https://leetcode.com/problems/gas-station/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{

    int gasSum = 0, costSum = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        gasSum += gas[i];
        costSum += cost[i];
    }
    if (gasSum < costSum)
    {
        return -1;
    }

    int start = 0;
    int currgas = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        currgas += gas[i] - cost[i];
        if (currgas < 0)
        {
            currgas = 0;
            start = i + 1;
        }
    }
    return start;
}

int main()
{

    return 0;
}