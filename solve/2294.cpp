// https://www.acmicpc.net/problem/2294

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int INT_INF = 999'999'999;
int n, k;
int values[111];
int dp[111][11111];

int solve(int c, int v)
{
    if (c >= n && v == 0)
        return 0;
    if (c >= n || v < 0)
        return INT_INF;
    
    int& res = dp[c][v];
    if (res != -1)
        return res;
    return res = min(solve(c, v - values[c]) + 1, solve(c + 1, v));
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 111; i++)
    for (int j = 0; j < 11111; j++)
        dp[i][j] = -1;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int result = solve(0, k);
    if (result < INT_INF)
        cout << result << "\n";
    else
        cout << "-1\n";
    return 0;
}