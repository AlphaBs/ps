// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int dp[1111][1111];
string a, b;

int solve(int i, int j)
{
    if (i >= a.length() || j >= b.length())
        return 0;
    
    int& res = dp[i][j];
    if (res != -1)
        return res;

    res = max(solve(i + 1, j), solve(i, j + 1));
    if (a[i] == b[j])
        res = max(res, solve(i + 1, j + 1) + 1);
    return res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 1111; i++)
    for (int j = 0; j < 1111; j++)
        dp[i][j] = -1;
        
    cin >> a >> b;
    cout << solve(0, 0);

    return 0;
}