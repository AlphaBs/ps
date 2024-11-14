// https://www.acmicpc.net/problem/2294

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 999'999'999;
int n, k;
int coins[111];
int dp[111][11'111];

int solve(int index, int value)
{
    if (index == n && value == 0)
        return 0;
    if (index == n || value < 0)
        return INF;

    int& ret = dp[index][value];
    if (ret >= 0) return ret;
    return ret = min(solve(index, value - coins[index]) + 1, solve(index + 1, value));
}

int main() 
{
    for (int i = 0; i < 111; i++)
    for (int j = 0; j < 11'111; j++)
        dp[i][j] = INF;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }

    for (int i = 0; i < 111; i++)
        dp[i][0] = 0;
        
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        while (true)
        {
            int remain = k - coins[i] * count;
            if (remain < 0) break;
            dp[i][remain] = min(dp[i][remain], dp[i - 1][remain] + count);
            count++;
        }
    }
    cout << dp[n][k];
    return 0;
}