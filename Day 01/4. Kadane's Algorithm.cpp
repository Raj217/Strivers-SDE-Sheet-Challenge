// https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Implementing Kadane's Algorithm

        int maxSum = INT_MIN;
        int sum = 0;
        for (int num: nums) {
            sum += num;

            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0; // Carying a negative sum will decrease the overall sum so of no use
        }
        return maxSum;
    }
};