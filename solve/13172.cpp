#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

ll n;
const ll x = 1'000'000'007;

ll sq(ll a, ll b)
{
    // a^b
    if (b == 0)
        return 1;

    ll part = sq(a, b / 2);
    ll result = (part * part) % x;
    if (b % 2 == 1)
        result = (result * a) % x;
    return result;
}

ll convert(ll a, ll b)
{
    // a * b^-1 mod x
    // b^-1 * b === 1 (mod x)
    // b^x-1 === 1 (mod x)
    // b^x-2 === b^-1 (mod x)

    ll inverseB = sq(b, x - 2);
    return (a * inverseB) % x;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    ll result = 0;
    for (ll i = 0; i < n; i++)
    {
        int n, s;
        cin >> n >> s;

        // S / N
        result = (convert(s, n) + result) % x;
    }

    cout << result;
    return 0;
}