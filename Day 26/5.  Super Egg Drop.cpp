// https://leetcode.com/problems/super-egg-drop/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

        for (int i=0; i<=k; i++) {
            // If there is 0 floor we need 0 check
            dp[i][0] = 0;
            // If there is 1 floor we need 1 check
            dp[i][1] = 1;
        }
        for (int i=0; i<=n; i++) {
            // If there is only 1 egg we need to check each floor
            dp[1][i] = i;
        }

        for (int egg=2; egg<=k; egg++) {
            for (int floor=2; floor<=n; floor++) {
                int low = 1, high = floor;
                int minMoves = INT_MAX;
                while (low <= high) {
                    int mid = low + (high-low)/2;
                    int broke = dp[egg-1][mid-1];
                    int safe = dp[egg][floor-mid];

                    // Since we are certain that after the provided moves we will find the drop
                    // We have to take the maximum of both dropping the egg and not dropping
                    minMoves = min(minMoves, max(broke, safe));
                    if (broke < safe) low = mid+1;
                    else high = mid-1;
                }
                dp[egg][floor] = minMoves+1;
            }
        }
        return dp[k][n];
    }
};