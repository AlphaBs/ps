// https://www.acmicpc.net/problem/1010

#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

ll nCr(ll n, ll r)
{
    if (r > n) return 0;
    if (r > n - r) r = n - r;

    ll result = 1;
    for (int i = 0; i < r; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        ll n, r;
        cin >> r >> n;
        cout << nCr(n, r) << '\n';
    }

    return 0;
}