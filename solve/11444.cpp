// https://www.acmicpc.net/problem/11444

#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll unsigned long long
#define MOD 1'000'000'007

using namespace std;

inline ll g(ll y, ll x)
{
    return y * 2 + x;
}

void multiplyMatrix(ll* a, ll* b)
{
    ll z = ((a[0] * b[0]) % MOD + (a[1] * b[2]) % MOD) % MOD;
    ll x = ((a[0] * b[1]) % MOD + (a[1] * b[3]) % MOD) % MOD;
    ll c = ((a[2] * b[0]) % MOD + (a[3] * b[2]) % MOD) % MOD;
    ll v = ((a[2] * b[1]) % MOD + (a[3] * b[3]) % MOD) % MOD;
    a[0] = z; a[1] = x; a[2] = c; a[3] = v;
}

void powerMatrix(ll* result, ll exp)
{
    if (exp == 0 || exp == 1)
        return;
    ll base[4] = {1, 1, 1, 0};
    powerMatrix(result, exp / 2);
    multiplyMatrix(result, result);
    if (exp % 2 == 1)
        multiplyMatrix(result, base);
}

ll fib(ll n)
{
    if (n == 0) return 0;
    ll base[4] = {1, 1, 1, 0};
    powerMatrix(base, n - 1);
    return base[0];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll input;
    cin >> input;
    cout << fib(input);
    return 0;
}