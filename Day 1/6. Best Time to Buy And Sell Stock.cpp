#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int currMaxProfit = INT_MIN;
        int buyDay = 0, currDay = 0, totalDays = prices.size();
        while (currDay < totalDays)
        {
            int profit = prices[currDay] - prices[buyDay];
            if (profit > currMaxProfit)
            {
                currMaxProfit = profit;
            }
            else if (profit < 0)
            {
                // If the profit is negative, the stock is buyable since it's price decreased
                buyDay = currDay;
            }
            currDay++;
        }
        return currMaxProfit;
    }
};
