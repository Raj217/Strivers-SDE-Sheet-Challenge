// https://leetcode.com/problems/implement-stack-using-queues/description/

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        if (q1.empty())
        {
            q2.push(x);
        }
        else
        {
            q1.push(x);
        }
    }

    int pop()
    {
        int x;
        if (q1.empty())
        {
            x = q2.front();
            q2.pop();
            while (!q2.empty())
            {
                q1.push(x);
                x = q2.front();
                q2.pop();
            }
        }
        else
        {
            x = q1.front();
            q1.pop();
            while (!q1.empty())
            {
                q2.push(x);
                x = q1.front();
                q1.pop();
            }
        }
        return x;
    }

    int top()
    {
        int x = pop();
        push(x);
        return x;
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};