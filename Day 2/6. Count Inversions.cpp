#include <bits/stdc++.h>
using namespace std;

void merge(long long *arr, int start, int mid, int end)
{
    vector<int> sorted(end - start + 1);
    int n1 = mid, n2 = end, i = 0, i1 = start;
    mid++;
    while (start <= n1 && mid <= n2)
    {
        if (arr[start] < arr[mid])
        {
            sorted[i++] = arr[start++];
        }
        else
        {
            sorted[i++] = arr[mid++];
        }
    }

    while (start <= n1)
    {
        sorted[i++] = arr[start++];
    }

    while (mid <= n2)
    {
        sorted[i++] = arr[mid++];
    }
    for (int i = i1; i <= end; i++)
    {
        arr[i] = sorted[i - i1];
    }
}

long long inversions(long long *arr, int start, int mid, int end)
{
    long long count = 0;

    int i1 = start, i2 = mid + 1, n1 = mid, n2 = end;

    while (i1 <= n1 && i2 <= n2)
    {
        if (arr[i1] > arr[i2])
        {
            count += n1 - i1 + 1;
            i2++;
        }
        else
        {
            i1++;
        }
    }
    return count;
}

long long countInversions(long long *arr, int start, int end)
{
    long long count = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        count += countInversions(arr, start, mid);
        count += countInversions(arr, mid + 1, end);

        count += inversions(arr, start, mid, end);

        merge(arr, start, mid, end);
    }
    return count;
}
long long getInversions(long long *arr, int n)
{
    return countInversions(arr, 0, n - 1);
}