// https://www.acmicpc.net/problem/11049

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

#define pii pair<int, int>
#define ll long long

using namespace std;

int n;
ll dp[555][555];
pii arr[555];

ll solve(int start, int end)
{
    ll& ret = dp[start][end];
    if (ret >= 0) return ret;

    if (start == end)
        return 0;

    ret = LONG_LONG_MAX;
    for (int i = start; i < end; i++)
    {
        ll cost = solve(start, i) + solve(i + 1, end) + arr[start].first * arr[i].second * arr[end].second;
        ret = min(ret, cost);
    }
    return ret;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 555; i++)
    for (int j = 0; j < 555; j++)
        dp[i][j] = -1;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r, c;
        cin >> r >> c;
        arr[i] = make_pair(r, c);
    }
    cout << solve(0, n - 1);
    return 0;
}