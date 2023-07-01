// https://www.codingninjas.com/studio/problems/complete-string_2687860?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

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
        root->isEnd = true;
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
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c: prefix) {
            if (!curr->containsKey(c) || !curr->isEnd) return false;
            curr = curr->get(c);
        }
        return true;
    }
}; 
string completeString(int n, vector<string> &a){
    sort(a.begin(), a.end());
    Trie trie;
    string ans;
    for (string word: a) {
        trie.insert(word);
    }
    for (string word: a) {
        if (trie.startsWith(word) && word.size() > ans.size()) {
            ans = word;
        }
    }
    return ans.size() == 0 ? "None" : ans;
}