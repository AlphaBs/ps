// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int w[111];
int v[111];
int dp[111][111'111];

int solve(int i, int c)
{
    if (i >= n || c < 0)
        return 0;

    int& ret = dp[i][c];
    if (ret >= 0)
        return ret;
    
    ret = solve(i + 1, c);
    if (w[i] <= c)
        ret = max(ret, solve(i + 1, c - w[i]) + v[i]);
    return ret;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 111; i++)
        for (int j = 0; j < 111'111; j++)
            dp[i][j] = -1;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    cout << solve(0, k);
    return 0;
}