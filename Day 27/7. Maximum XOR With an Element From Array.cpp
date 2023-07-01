// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];

    bool containsKey(int bit) { return links[bit] != NULL; }
    void set(int bit, Node* node) { links[bit] = node; }
    Node* get(int bit) { return links[bit]; }    
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* curr = root;
        for (int i=31; i>=0; i--) {
            int bit = (num>>i) & 1;
            if (!curr->containsKey(bit)) {
                curr->set(bit, new Node());
            }
            curr = curr->get(bit);
        }
    }

    int getMaxXor(int num) {
        Node* curr = root;
        int maxNum = 0;
        for (int i=31; i>=0; i--) {
            if (!curr) return -1;
            int bit = (num>>i) & 1;
            if (bit == 0) {
                if (curr->containsKey(1)) {
                    maxNum |= (1<<i);
                    curr = curr->get(1);
                } else {
                    curr = curr->get(0);
                }
            } else {
                if (curr->containsKey(0)) {
                    maxNum |= (1<<i);
                    curr = curr->get(0);
                } else {
                    curr = curr->get(1);
                }
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n, 0);
        vector<vector<int>> queriesModified;
        for (int i=0; i<n; i++) {
            queriesModified.push_back({queries[i][1], i, queries[i][0]});
        }

        sort(nums.begin(), nums.end());
        sort(queriesModified.begin(), queriesModified.end());

        Trie trie;
        int ind = 0;
        for (int i=0; i<n; i++) {
            int m = queriesModified[i][0];
            int j = queriesModified[i][1];
            int num = queriesModified[i][2];
            while (ind<nums.size() && nums[ind] <= m) {
                trie.insert(nums[ind++]);
            }
            ans[j] = trie.getMaxXor(num);
        }
        return ans;
    }
};