#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int mp = 0;
    int profit = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > profit)
        {
            mp = max(mp,prices[i]-profit);
        }

        profit = min(profit,prices[i]);
        
    }
    return mp;
}

int main()
{
    vector<int> vec = {1,8,6,2,5,4,8,3,7};

    cout << maxProfit(vec);

    return 0;
}