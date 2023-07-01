// https://www.codingninjas.com/studio/problems/number-of-distinct-substring_1465938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool isEnd=false;

    bool containsKey(char c) { return links[c-'a'] != NULL; }
    void set(char c, Node* node) { links[c-'a'] = node; }
    Node* get(char c) { return links[c-'a']; }
};

class Trie {
private:
    Node* root;
public:
    Trie() { root = new Node(); }
    int insert(string word) {
        Node* curr = root;
        int newNodesInserted = 0;
        for (char c: word) {
            if (!curr->containsKey(c)) {
                newNodesInserted++;
                curr->set(c, new Node());
            }
            curr = curr->get(c);
        }
        curr->isEnd = true;
        return newNodesInserted;
    }
};
int distinctSubstring(string &word) {
    int substrings = 0;
    Trie trie;
    for (int i=0; i<word.size(); i++) {
        substrings += trie.insert(word.substr(i));
    }
    return substrings;
}