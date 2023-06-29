// https://www.codingninjas.com/studio/problems/920336?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> ans;
    unordered_map<int, int> freq;
    int left = 0, right = 0;
    while (right < k) {
        freq[arr[right]]++;
        right++;
    }
	right--;
    int distinct = 0;
    for (auto f: freq) {
        distinct++;
    }
    while (right < arr.size()) {
        ans.push_back(distinct);
        freq[arr[left]]--;
        if (freq[arr[left]] == 0) distinct--;
        left++;
        right++;
        if (right<arr.size()) {
            freq[arr[right]]++;
            if (freq[arr[right]] == 1) distinct++;
        }
    }
    return ans;
}