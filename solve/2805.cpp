// https://www.acmicpc.net/problem/2805

#define ll long long
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

ll n, m;
ll trees[1'111'111];

bool check(ll h)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += max(0LL, trees[i] - h);
    }
    return sum >= m;
}

ll solve()
{
    ll lo = 0;
    ll hi = 1'111'111'111;
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll v;
        cin >> v;
        trees[i] = v;
    }

    cout << solve();
    return 0;
}