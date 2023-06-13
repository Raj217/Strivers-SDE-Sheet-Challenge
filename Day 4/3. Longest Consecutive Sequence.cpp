// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
    
    void insert(int node) {
        if (parent.find(node) == parent.end()) {
            parent[node] = node;
            size[node] = 1;
        }
    }
public:
    DisjointSet() {
        parent = {};
        size = {};
    }
    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void makeUnion(int u, int v) {
        insert(u), insert(v);

        int pU = find(u);
        int pV = find(v);

        if (pU == pV) return;

        int sU = size[pU], sV = size[pV];

        if (sU > sV) {
            parent[pV] = pU;
            size[pU] += size[pV];
        } else if (sU < sV) {
            parent[pU] = pV;
            size[pV] += size[pU];
        } else {
            parent[pV] = pU;
            size[pU] += size[pV];
        }
    } 
    int maxSize() {
        int maxi = 1;
        for (auto s: size) {
            if (s.second > maxi) {
                maxi = s.second;
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> numsSet(nums.begin(), nums.end());

        DisjointSet dj;
        for (int num: nums) {
            if (numsSet.find(num-1) != numsSet.end()) {
                dj.makeUnion(num-1, num);
            }
            if (numsSet.find(num+1) != numsSet.end()) {
                dj.makeUnion(num+1, num);
            }
        }
        return dj.maxSize();
    }
};