// https://www.acmicpc.net/problem/1629

#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

int a, b, c;

ll solve(int k)
{
    if (k == 1) 
        return a % c;

    if (k % 2 == 0)
    {
        ll part = solve(k / 2);
        return ((part % c) * (part % c)) % c;
    }
    else
    {
        return (a * (solve(k - 1) % c)) % c;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    cout << solve(b);
    return 0;
}