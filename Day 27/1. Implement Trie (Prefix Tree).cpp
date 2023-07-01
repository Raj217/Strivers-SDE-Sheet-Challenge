// https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool isEnd = false;

    bool containsKey(char c) {
        return links[c-'a'] != NULL;
    }
    void set(char c, Node* node) {
        links[c-'a'] = node;
    }
    Node* get(char c) {
        return links[c-'a'];
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (char c: word) {
            if (!curr->containsKey(c)) {
                curr->set(c, new Node());
            }
            curr = curr->get(c);
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c: word) {
            if (!curr->containsKey(c)) return false;
            curr = curr->get(c);
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c: prefix) {
            if (!curr->containsKey(c)) return false;
            curr = curr->get(c);
        }
        return true;
    }
};