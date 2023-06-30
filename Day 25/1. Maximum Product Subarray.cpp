// https://leetcode.com/problems/maximum-product-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixPro(n, 1);
        vector<long long> suffixPro(n, 1);
        prefixPro[0] = nums[0];
        suffixPro[n-1] = nums[n-1];

        for (int i=1; i<n; i++) {
            if (prefixPro[i-1] == 0) prefixPro[i] = nums[i];
            else prefixPro[i] = nums[i]*prefixPro[i-1];
            if (suffixPro[n-i] == 0) suffixPro[n-i-1] = nums[n-i-1];
            else suffixPro[n-i-1] = nums[n-i-1]*suffixPro[n-i];
        }

        long long maxPro = LLONG_MIN;
        for (int i=0; i<n; i++) {
            maxPro = max({maxPro, prefixPro[i]*suffixPro[i]/(nums[i] == 0 ? 1 : nums[i]), prefixPro[i], suffixPro[i]});
        }
        return maxPro;
    }
};