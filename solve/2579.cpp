// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int arr[333];
int dp[333][5];

int solve(int i, int continueCount)
{
    if (i >= n || continueCount >= 3)
        return -999'999'999;
    if (i == n - 1)
        return arr[i];

    int& res = dp[i][continueCount];
    if (res != 0)
        return res;
    return res = arr[i] + max(solve(i + 1, continueCount + 1), solve(i + 2, 1));
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        
    }

    cout << max(solve(0, 1), solve(1, 1)) << endl;
    return 0;
}