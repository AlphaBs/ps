// https://www.acmicpc.net/problem/7579

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int M[111];
int C[111];
int dp[111][111'111];

// 비용이 c 일때 최대 M
int solve(int app, int c)
{
    if (app > n)
        return 0;

    int& ret = dp[app][c];
    if (ret != -1)
        return ret;

    ret = solve(app + 1, c);
    if (c >= C[app])
        ret = max(ret, solve(app + 1, c - C[app]) + M[app]);
    return ret;
}

int main() 
{   
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), -1);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> M[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> C[i];
    }

    int minCost = 111'111;
    for (int i = 111'000; i >= 0; i--)
    {
        int s = solve(1, i);
        if (s >= m)
            minCost = i;
    }
    cout << minCost;
    return 0;
}