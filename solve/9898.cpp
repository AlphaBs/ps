// https://www.acmicpc.net/problem/9898

#include <iostream>
#include <cstdio>
#include <algorithm>
#define MODER 1000
#define ll long long

using namespace std;

ll dp[5][1111];

int solve(int n, int state)
{
    ll& ret = dp[state][n];
    if (ret != 0)
        return ret;

    if (state == 0)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        ret += solve(n - 1, 0);
        ret %= MODER;
        ret += solve(n - 2, 0);
        ret %= MODER;
        ret += solve(n - 1, 3);
        ret %= MODER;
        ret += solve(n - 1, 1);
        ret %= MODER;
        ret += solve(n - 1, 2);
        ret %= MODER;
    }
    else if (state == 1)
    {
        if (n < 1)
            return 0;
        if (n == 1)
            return 1;

        ret += solve(n - 1, 0);
        ret %= MODER;
        ret += solve(n - 1, 3);
        ret %= MODER;
    }
    else if (state == 2)
    {
        if (n < 1)
            return 0;
        if (n == 1)
            return 1;

        ret += solve(n - 1, 0);
        ret %= MODER;
        ret += solve(n - 1, 4);
        ret %= MODER;
    }
    else if (state == 3)
    {
        if (n < 1)
            return 0;
        if (n == 1)
            return 1;

        ret += solve(n - 1, 0);
        ret %= MODER;
        ret += solve(n - 1, 1);
        ret %= MODER;
    }
    else if (state == 4)
    {
        ret += solve(n - 1, 2);
        ret %= MODER;
    }

    return ret;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    if (n == 0)
        cout << 0;
    else
        cout << solve(n, 0);

    return 0;
}