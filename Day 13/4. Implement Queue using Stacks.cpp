// https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> front, back;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!back.empty()) {
            front.push(back.top());
            back.pop();
        }
        front.push(x);
    }
    
    int pop() {
        while (!front.empty()) {
            back.push(front.top());
            front.pop();
        }
        int x = back.top();
        back.pop();
        return x;
    }
    
    int peek() {
        int x = pop();
        back.push(x);
        return x;
    }
    
    bool empty() {
        return front.empty() && back.empty();
    }
};
