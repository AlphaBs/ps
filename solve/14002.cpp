// https://www.acmicpc.net/problem/14002

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int arr[1111];
int dp[1111];
int lis[1111];

// return the length of LIS which of the first element is arr[index]
int solve(int index)
{
    if (index == n)
        return 1;

    int& res = dp[index];
    if (res != -1)
        return res;

    res = 1;
    for (int i = index + 1; i <= n; i++)
    {
        if (arr[index] < arr[i])
        {
            int next = solve(i) + 1;
            if (res < next)
            {
                res = next;
                lis[index] = i;
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 1111; i++)
    {
        dp[i] = -1;
        lis[i] = -1;
    }

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cout << solve(0) - 1 << '\n';
    int i = 0;
    while (lis[i] != -1)
    {
        cout << arr[lis[i]] << ' ';
        i = lis[i];
    }

    return 0;
}