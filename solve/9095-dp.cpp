#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[12];

int f(int n)
{
    if (n == 1) // 1
        return 1;
    if (n == 2) // 1+1, 2
        return 2;
    if (n == 3) // 1+1+1, 1+2, 2+1, 3
        return 4;

    if (dp[n] != 0)
        return dp[n];

    return dp[n] = f(n-1) + f(n-2) + f(n-3);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (--t >= 0)
    {
        int n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}