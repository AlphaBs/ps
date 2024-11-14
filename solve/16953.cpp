// https://www.acmicpc.net/problem/16953

#include <iostream>
#include <cstdio>
#include <algorithm>

#define INT_MAX 2'000'000'000
#define ll long long

using namespace std;

ll A, B;

ll solve(ll a)
{
    if (a == B) return 0;
    if (a > B) return INT_MAX;

    ll result = min(solve(a * 2), solve(a * 10 + 1)) + 1;
    return result;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B;
    ll result = solve(A);
    if (result <= INT_MAX)
        cout << result + 1;
    else
        cout << -1;

    return 0;
}