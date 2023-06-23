// https://leetcode.com/problems/sliding-window-maximum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // We can make a deque which keeps only the bigger incoming elements
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            // If it is the outgoing number 
            // Even if it is greatest we need to remove it
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            
            // Next: We store only the larger incoming one
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};