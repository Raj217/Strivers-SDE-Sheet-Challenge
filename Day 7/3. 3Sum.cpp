// https://leetcode.com/problems/3sum/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (left > i + 1 && nums[left] == nums[left - 1])
                {
                    left++;
                    continue;
                }
                if (right + 1 < n && nums[right] == nums[right + 1])
                {
                    right--;
                    continue;
                }
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ans;
    }
};