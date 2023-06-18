// https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void findWords(string &s, unordered_set<string> &dict, int i, int j, string sentence, vector<string> &ans)
{
    if (j == s.size())
    {
        sentence.pop_back();
        if (i == j)
        {
            ans.push_back(sentence);
        }
        return;
    }

    string word = s.substr(i, j - i + 1);
    if (dict.find(word) != dict.end())
    {
        findWords(s, dict, j + 1, j + 1, sentence + word + " ", ans);
    }
    findWords(s, dict, i, j + 1, sentence, ans);
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    findWords(s, dict, 0, 0, "", ans);
    return ans;
}