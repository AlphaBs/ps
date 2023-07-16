// https://www.acmicpc.net/problem/11659

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
long long sum[111'111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> sum[1];
    for (int i = 2; i <= n; i++)
    {
        int t;
        cin >> t;
        sum[i] = sum[i - 1] + t;
    }

    for (int l = 0; l < m; l++)
    {
        int i, j;
        cin >> i >> j;
        cout << (sum[j] - sum[i - 1]) << "\n";
    }

    return 0;
}