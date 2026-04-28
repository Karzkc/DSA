https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

# Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104

## Solution

To solve this problem, we need to find the maximum profit from buying and selling a stock once, where we buy on one day and sell on a later day. If no profit is possible, return 0.

### Approach

We can use a single pass through the array to track the minimum price seen so far (best buy) and the maximum profit achievable.

### Steps

1. Initialize `bestBuy` to the first element of the array (`prices[0]`).
2. Initialize `maxProfit` to 0.
3. Iterate through the array starting from the second element:
   - If the current price is greater than `bestBuy`, calculate the potential profit (`current price - bestBuy`) and update `maxProfit` to the maximum of its current value and this profit.
   - If the current price is less than `bestBuy`, update `bestBuy` to the current price.
4. After the loop, return `maxProfit`.

This approach ensures we always consider the lowest buy price before calculating profits.

### Example Walkthrough

- For `prices = [7,1,5,3,6,4]`:
  - Start with `bestBuy = 7`, `maxProfit = 0`.
  - At price 1: 1 < 7, so `bestBuy = 1`.
  - At price 5: 5 > 1, so `maxProfit = max(0, 5-1) = 4`.
  - At price 3: 3 > 1, so `maxProfit = max(4, 3-1) = 4`.
  - At price 6: 6 > 1, so `maxProfit = max(4, 6-1) = 5`.
  - At price 4: 4 > 1, so `maxProfit = max(5, 4-1) = 5`.
  - Result: 5.

### Time Complexity

- O(n), where n is the length of the array, as we make a single pass.

### Space Complexity

- O(1), using only a few variables.

### Code

```
int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
```
