// https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

int findCelebrity(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // Remove who knows each other
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(a, b))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    int probableCelebrity = st.top();
    bool doesSomeoneKnowCelebrity = false;
    for (int i = 0; i < n; i++)
    {
        if (knows(probableCelebrity, i) && i != probableCelebrity)
        {
            return -1;
        }
        doesSomeoneKnowCelebrity |= knows(i, probableCelebrity);
    }
    if (doesSomeoneKnowCelebrity)
        return probableCelebrity;
    return -1;
}