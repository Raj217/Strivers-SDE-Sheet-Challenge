// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num: nums) {
            pq.push(num);
        }
        while (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};