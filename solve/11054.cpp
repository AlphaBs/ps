// https://www.acmicpc.net/problem/11054

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int arr[1111];
int memFront[1111];
int memBack[1111];

int getFrontLIS(int start)
{
    if (start < 0)
        return 0;

    int& result = memFront[start];
    if (result > 0)
        return result;

    result = 1;
    for (int i = start - 1; i >= 0; i--)
    {
        if (arr[start] > arr[i])
            result = max(result, 1 + getFrontLIS(i));
    }

    return result;
}

int getBackLIS(int start)
{
    if (start >= n)
        return 0;
    
    int& result = memBack[start];
    if (result > 0)
        return result;

    result = 1;
    for (int i = start + 1; i < n; i++)
    {
        if (arr[start] > arr[i])
            result = max(result, 1 + getBackLIS(i));
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        //cout << "i=" << i << " " << getFrontLIS(i) << "," << getBackLIS(i) << "\n";
        maxLen = max(maxLen, getFrontLIS(i) + getBackLIS(i) - 1);
    }

    cout << maxLen;
    return 0;
}