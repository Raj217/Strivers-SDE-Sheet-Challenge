// https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount)
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int minCoins = 0, c = 0;
    for (int i = coins.size() - 1; i >= 0; i--)
    {
        c = amount / coins[i];
        amount -= c * coins[i];
        minCoins += c;
        if (amount <= 0)
            break;
    }
    return minCoins;
}
