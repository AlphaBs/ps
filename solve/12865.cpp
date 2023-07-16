// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, maxWeight;
int w[111];
int v[111];
int cache[2][111'111]; // [index][weight]

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> maxWeight;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int currentWeight = 0; currentWeight <= maxWeight; currentWeight++)
        {
            int& maxResult = cache[i%2][currentWeight];
            maxResult = cache[(i-1)%2][currentWeight];
            if (currentWeight + w[i] <= maxWeight)
                maxResult = max(maxResult, cache[(i-1)%2][currentWeight + w[i]] + v[i]);
        }
    }

    cout << cache[n%2][0];

    return 0;
}