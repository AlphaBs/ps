// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int w[111];
int v[111];
int cache[111][111'111];

// dp[index][maxWeight] = max(do not pack `index` item, pack `index` item)
// dp[index][maxWeight] = max(dp[index-1][maxWeight], dp[index-1][maxWeight-w[index]]+v[index])
int pack(int index, int weight)
{
    if (index >= n)
        return 0;

    int& ret = cache[index][weight];
    if (ret > 0)
        return ret;

    // pack index
    if (weight + w[index] <= k)
        ret = max(ret, pack(index + 1, weight + w[index]) + v[index]);

    // do not pack index
    ret = max(ret, pack(index + 1, weight));

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << pack(0, 0);

    return 0;
}