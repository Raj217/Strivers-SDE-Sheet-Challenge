// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxXor = 0;
        for (int i=0; i<nums.size(); i++) {
            trie.insert(nums[i]);
            maxXor = max(maxXor, trie.getMaxXor(nums[i]));
        }
        return maxXor;
    }
};