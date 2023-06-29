// https://leetcode.com/problems/find-median-from-data-stream/description/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || left.top() > num) {
            left.push(num);
        } else {
            right.push(num);
        }
        int nLeft = left.size();
        int nRight = right.size();
        if (nLeft - nRight > 1) {
            right.push(left.top());
            left.pop();
        } else if (nRight> nLeft) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        int mid1 = left.top();
        if (left.size() == right.size()) {
            int mid2 = right.top();
            return (mid1+mid2)/2.0;
        } else {
            return mid1;
        }
    }
};