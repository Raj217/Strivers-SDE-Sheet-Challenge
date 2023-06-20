// https://leetcode.com/problems/top-k-frequent-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto element: freq) {
            pq.push({element.second, element.first});
        }
        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};