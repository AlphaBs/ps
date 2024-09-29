#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MODDER = 10'007;
int dp[1'111];

int f(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (dp[n] > 0)
        return dp[n];
    return dp[n] = (f(n - 1) % MODDER + f(n - 2) % MODDER) % MODDER;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    cout << f(n);

    return 0;
}