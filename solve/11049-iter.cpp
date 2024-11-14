// https://www.acmicpc.net/problem/11049

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

#define pii pair<int, int>
#define ll long long

using namespace std;

int n;
ll dp[555][555];
pii arr[555];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r, c;
        cin >> r >> c;
        arr[i] = make_pair(r, c);
    }

    for (int size = 2; size <= n; size++)
    {
        for (int start = 0; start + size <= n; start++)
        {
            ll m = LONG_LONG_MAX;
            for (int leftSize = 1; leftSize < size; leftSize++)
            {
                int rightStart = start + leftSize;
                int rightSize = size - leftSize;
                m = min(m, 
                    dp[leftSize][start] + 
                    dp[rightSize][rightStart] + 
                    arr[start].first * arr[rightStart - 1].second * arr[rightStart + rightSize - 1].second);
            }
            dp[size][start] = m;
        }
    }
    cout << dp[n][0];
    return 0;
}