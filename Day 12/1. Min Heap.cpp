// https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &nums, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < n && nums[left] < nums[smallest])
    {
        smallest = left;
    }
    if (right < n && nums[right] < nums[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(nums[i], nums[smallest]);
        heapify(nums, smallest, n);
    }
}
void insert(vector<int> &nums, int num, int &size)
{
    nums[size] = num;

    int i = size++;

    while (i > 0 && nums[(i - 1) / 2] > nums[i])
    {
        swap(nums[i], nums[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
vector<int> minHeap(int n, vector<vector<int>> &q)
{
    vector<int> v(n, 0);
    int size = 0;
    vector<int> ans;
    for (vector<int> query : q)
    {
        if (query[0] == 0)
        {
            insert(v, query[1], size);
        }
        else
        {
            ans.push_back(v[0]);
            swap(v[0], v[--size]);
            heapify(v, 0, size);
        }
    }
    return ans;
}