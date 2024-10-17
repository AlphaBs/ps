// https://www.acmicpc.net/problem/1149

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int cl[3][1111];
int dp[3][1111];

int solve(int color, int i)
{
    if (i == n - 1)
    {
        return cl[color][i];
    }

    int& ret = dp[color][i];
    if (ret > 0)
        return ret;

    if (color == 0)
    {
        ret = cl[0][i] + min(solve(1, i + 1), solve(2, i + 1));
    }
    else if (color == 1)
    {
        ret = cl[1][i] + min(solve(0, i + 1), solve(2, i + 1));
    }
    else if (color == 2)
    {
        ret = cl[2][i] + min(solve(0, i + 1), solve(1, i + 1));
    }

    return ret;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cl[0][i] >> cl[1][i] >> cl[2][i];
    cout << min(min(solve(0, 0), solve(1, 0)), solve(2, 0));
    return 0;
}