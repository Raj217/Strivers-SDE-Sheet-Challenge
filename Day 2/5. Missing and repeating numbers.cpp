#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int duplicate;
    // Using index sort
    for (int i = 0; i < n;)
    {
        // Already in place
        if (arr[i] == i + 1)
        {
            i++;
        }
        else
        {
            if (arr[i] == arr[arr[i] - 1])
            {
                duplicate = arr[i];
                break;
            }
            else
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
    }
    int sum = accumulate(begin(arr), end(arr), 0);
    int expectedSum = n * (n + 1) / 2;

    return {expectedSum - sum + duplicate, duplicate};
}
