// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &stack)
{
	if (stack.size() <= 1) return;
	int x = stack.top(); stack.pop();
	sortStack(stack);
	if (x > stack.top()) {
		stack.push(x);
	} else {
		std::stack<int> temp;
		while (!stack.empty() && stack.top() > x) {
			temp.push(stack.top());
			stack.pop();
		}
		stack.push(x);
		while (!temp.empty()) {
			stack.push(temp.top());
			temp.pop();
		}
	}
}