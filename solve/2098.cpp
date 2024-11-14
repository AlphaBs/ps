// https://www.acmicpc.net/problem/2098

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>

#define INT_MAX 99'999'999

using namespace std;

typedef bitset<16> bset;

int n;
int W[22][22];
int dp[22][1<<17];

int find(int last, bset set)
{
    if (set.count() == n)
        return W[last][0];

    int& ret = dp[last][set.to_ulong()];
    if (ret != -1)
        return ret;

    ret = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (!set.test(i))
        {
            bset next = set;
            next.set(i);
            ret = min(ret, find(i, next) + W[last][i]);
        }
    }
    return ret;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), -1);

    cin >> n;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        cin >> W[y][x];
        if (W[y][x] == 0)
            W[y][x] = INT_MAX;
    }

    cout << find(0, bset(1));
    return 0;
}