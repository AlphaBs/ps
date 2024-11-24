// https://www.acmicpc.net/problem/11049

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

ll n;
ll R[555];
ll C[555];
ll dp[555][555];

ll find(ll start, ll end)
{
    ll& ret = dp[start][end];
    if (ret != -1)
        return ret;

    if (end == start)
        return ret = 0;

    ret = 999'999'999'999;
    for (ll mid = start; mid <= end - 1; mid++)
    {
        ret = min(ret, find(start, mid) + find(mid + 1, end) + R[start] * C[mid] * C[end]);
    }
    return ret;
}

int main() 
{
    for (int i = 0; i < 555; i++)
    for (int j = 0; j < 555; j++)
        dp[i][j] = -1;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> R[i] >> C[i];
    }

    cout << find(0, n - 1);
    return 0;
}