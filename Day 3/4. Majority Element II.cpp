#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0, element1 = -1, element2 = -2;

        for (int num: nums) {
            if (count1 == 0 && element2 != num) {
                element1 = num;
                count1++;
            } else if (count2 == 0 && element1 != num) {
                element2 = num;
                count2++;
            } 
            else if (element1 == num) count1++;
            else if (element2 == num) count2++;
            else count1--, count2--;
        }

        count1 = 0, count2 = 0;
        for (int num: nums) {
            if (element1 == num) count1++;
            else if (element2 == num) count2++;
        }

        vector<int> ans;
        if (count1 > n/3) ans.push_back(element1);
        if (count2 > n/3) ans.push_back(element2);
        return ans; 
    }
};