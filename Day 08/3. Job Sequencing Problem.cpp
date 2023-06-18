// https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
             return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
         });
    vector<bool> isFree(1e5 + 1, true);
    int profit = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {
            if (isFree[j] == true)
            {
                isFree[j] = false;
                profit += jobs[i][1];
                break;
            }
        }
    }
    return profit;
}
