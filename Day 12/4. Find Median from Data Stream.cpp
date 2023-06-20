// https://leetcode.com/problems/find-median-from-data-stream/description/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty())
        {
            maxHeap.push(num);
        }
        else if (maxHeap.top() > num)
        {
            maxHeap.push(num);
            if (maxHeap.size() - minHeap.size() > 1)
            {
                num = maxHeap.top();
                maxHeap.pop();
                minHeap.push(num);
            }
        }
        else
        {
            minHeap.push(num);
            if (maxHeap.size() < minHeap.size())
            {
                num = minHeap.top();
                minHeap.pop();
                maxHeap.push(num);
            }
        }
    }

    double findMedian()
    {
        int x = maxHeap.top();
        int y = 0;
        if (!minHeap.empty())
        {
            y = minHeap.top();
        }
        if ((maxHeap.size() + minHeap.size()) % 2 == 0)
        {
            return (x + y) / 2.0;
        }
        else
        {
            return x;
        }
    }
};