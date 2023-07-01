// https://www.codingninjas.com/studio/problems/implement-trie_1387095?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int endWith = 0;
    int countPrefix = 0;

    bool containsKey(char c) { return links[c-'a'] != NULL; }
    void set(char c, Node* node) { links[c-'a'] = node; }
    Node* get(char c) { return links[c-'a']; }
};

class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* curr = root;
        for (char c: word) {
            if (!curr->containsKey(c)) {
                curr->set(c, new Node());
            }
            curr = curr->get(c);
            curr->countPrefix++;
        }
        curr->endWith++;
    }

    int countWordsEqualTo(string &word){
        Node* curr = root;
        for (char c: word) {
            if (!curr->containsKey(c)) return 0;
            curr = curr->get(c);
        }
        return curr->endWith;
    }

    int countWordsStartingWith(string &word){
        Node* curr = root;
        for (char c: word) {
            if (!curr->containsKey(c)) return 0;
            curr = curr->get(c);
        }
        return curr->countPrefix;
    }

    void erase(string &word){
        Node* curr = root;
        for (char c: word) {
            if (!curr->containsKey(c)) return;
            curr = curr->get(c);
            curr->countPrefix--;
        }
        curr->endWith--;
    }
};