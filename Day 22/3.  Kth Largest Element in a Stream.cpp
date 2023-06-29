// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int num: nums) {
            pq.push(num);
        }
        while (pq.size() > k) pq.pop(); 
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop(); 
        return pq.top();
    }
};
