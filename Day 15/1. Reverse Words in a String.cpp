// https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string next(string s, int &i) {
        string word;
        while (i<s.size() && s[i] == ' ') i++;
        while (i<s.size() && s[i] != ' ') {
            word.push_back(s[i++]);
        }
        return word;
    }
public:
    string reverseWords(string s) {
        vector<string> words;
        for (int i=0; i<s.size();) {
            string word = next(s, i);
            if (word.size() > 0) words.push_back(word);
        }
        string reversed;
        for (int i=words.size()-1; i>=0; i--) {
            reversed += words[i]+" ";
        }
        reversed.pop_back();
        return reversed;
    }
};