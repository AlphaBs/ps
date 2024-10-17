// https://www.acmicpc.net/problem/11053

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int arr[1111];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[1111];
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, dp[i]);
    cout << result;
    return 0;
}