// https://www.acmicpc.net/problem/9465

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t;
int n;
int arr[2][111'111];
int dp[3][111'111];

int solve(int x, int state)
{
    if (x >= n)
        return 0;

    int& ret = dp[state][x];
    if (ret >= 0)
        return ret;

    if (state == 0) // 위아래 모두사용가능
    {
        ret = max(ret, solve(x + 1, 0));
        ret = max(ret, solve(x + 1, 1) + arr[0][x]);
        ret = max(ret, solve(x + 1, 2) + arr[1][x]);
    }
    else if (state == 1) // 위쪽 사용불가
    {
        ret = max(ret, solve(x + 1, 0));
        ret = max(ret, solve(x + 1, 2) + arr[1][x]);
    }
    else if (state == 2) // 아래쪽 사용불가
    {
        ret = max(ret, solve(x + 1, 0));
        ret = max(ret, solve(x + 1, 1) + arr[0][x]);
    }
    return ret;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    for (; t > 0; t--)
    {
        // initialize dp
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 111'111; j++)
                dp[i][j] = -1;

        // input
        cin >> n;
        for (int y = 0; y < 2; y++)
            for (int x = 0; x < n; x++)
                cin >> arr[y][x];

        cout << solve(0, 0) << '\n';
    }

    return 0;
}