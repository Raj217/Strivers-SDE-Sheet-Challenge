// https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void dp(vector<int> &nums, int i, int sum, vector<int> &sums)
{
    if (i == nums.size())
    {
        sums.push_back(sum);
        return;
    }
    dp(nums, i + 1, sum, sums);
    dp(nums, i + 1, sum + nums[i], sums);
}
vector<int> subsetSum(vector<int> &num)
{
    sort(num.begin(), num.end());
    vector<int> sums;
    dp(num, 0, 0, sums);
    sort(sums.begin(), sums.end());
    return sums;
}