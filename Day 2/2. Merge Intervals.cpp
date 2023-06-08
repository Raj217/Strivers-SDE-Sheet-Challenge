#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];

        for (vector<int> interval : intervals)
        {
            // Overlapping
            if (interval[0] <= end)
            {
                end = max(end, interval[1]);
            }
            else
            {
                ans.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};