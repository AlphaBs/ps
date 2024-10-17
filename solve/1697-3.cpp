#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[111'111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int start, end;
    cin >> start >> end;

    for (int c = 0; c <= end; c++)
    {
        if (c <= start)
            dp[c] = abs(c - start);
        else if (c % 2 == 0)
            dp[c] = min(dp[c - 1] + 1, dp[c / 2] + 1);
        else
            dp[c] = min(dp[c - 1] + 1, dp[(c + 1) / 2] + 2);
    }

    cout << dp[end];
    return 0;
}