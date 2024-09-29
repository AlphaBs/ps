// https://www.acmicpc.net/problem/1003

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dp0[50];
int dp1[50];

int fib0(int n)
{
    if (dp0[n] != -1)
        return dp0[n];
    return dp0[n] = fib0(n - 1) + fib0(n - 2);
}

int fib1(int n)
{
    if (dp1[n] != -1)
        return dp1[n];
    return dp1[n] = fib1(n - 1) + fib1(n - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // initialize DP
    for (int i = 0; i < 50; i++) dp0[i] = -1;
    for (int i = 0; i < 50; i++) dp1[i] = -1;
    dp0[0] = 1;
    dp0[1] = 0;
    dp1[0] = 0;
    dp1[1] = 1;

    int t;
    cin >> t;
    while (--t >= 0)
    {
        int n;
        cin >> n;
        cout << fib0(n) << ' ' << fib1(n) << endl;
    }
    return 0;
}