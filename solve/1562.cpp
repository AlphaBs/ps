// https://www.acmicpc.net/problem/1562

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>

#define ll long long
#define MOD 1'000'000'000

using namespace std;

ll dp[11][111][1 << 11];

ll solve(int start, int length, int set)
{
    if (length == 1)
        return set == 0b1111111111 ? 1 : 0;

    ll& ret = dp[start][length][set];
    if (ret != -1)
        return ret;
    ret = 0;

    int upper = start + 1;
    if (upper <= 9)
    {
        ret += (solve(upper, length - 1, set | (1 << upper)) % MOD);
    }

    int lower = start - 1;
    if (lower >= 0)
    {
        ret += (solve(lower, length - 1, set | (1 << lower)) % MOD);
    }

    return ret %= MOD;
}

ll solve(int n)
{
    ll result = 0;
    for (int i = 1; i <= 9; i++)
    {
        result += (solve(i, n, 1 << i) % MOD);
        result %= MOD;
    }
    return result;
}

int main() 
{
    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(ll) , -1);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //ll t = 0;
    //for (int i = 1; i <= 40; i++)
    //{
    //    ll next = solve(i);
    //    cout << next << '\n';
    //    t += solve(i);
    //}
    //cout << t << '\n';

    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}