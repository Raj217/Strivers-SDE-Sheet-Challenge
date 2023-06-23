// https://leetcode.com/problems/online-stock-span/description/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> st;
    int day=0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int span;
        if (!st.empty()) span = day-st.top().second;
        else span = day+1;
        st.push({price, day});
        day++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */