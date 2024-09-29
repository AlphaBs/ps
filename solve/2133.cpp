// https://www.acmicpc.net/problem/2133

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// state0: 완전히 채워짐
// state1: 두개 채워짐

int dp[3][33];

int f(int n, int state)
{
    if (n == 0 && state == 0)
        return 1;
    if (n == 0 && state == 1)
        return 0;
    if (n == 1)
        return 0;

    int& ret = dp[state][n];
    if (ret > 0)
        return ret;

    if (state == 0)
    {
        ret += f(n - 2, 0) * 3;
        ret += f(n - 2, 1) * 2;
    }
    else if (state == 1)
    {
        ret += f(n - 2, 0);
        ret += f(n - 2, 1);
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
    cout << f(n, 0);

    return 0;
}