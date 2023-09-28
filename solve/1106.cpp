// https://www.acmicpc.net/problem/1106

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int c, n;
int cityCost[22];
int cityValue[22];

int mem[22][1111];

int findMinCost(int start, int requireValue)
{
    if (requireValue <= 0)
        return 0;
    if (start >= n)
        return 999'999'999;

    int& res = mem[start][requireValue];
    if (res >= 0)
        return res;

    int minCost = 999'999'999;
    int maxCount = (requireValue / cityValue[start]) + 1;
    for (int i = 0; i <= maxCount; i++)
    {
        int nextRequireValue = requireValue - (cityValue[start] * i);
        int nextCost = findMinCost(start + 1, nextRequireValue);

        minCost = min(minCost, nextCost + (cityCost[start] * i));
    }

    return res = minCost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(mem[0], mem[0] + 22*1111, -1);

    cin >> c >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cityCost[i] >> cityValue[i];
    }

    cout << findMinCost(0, c);
    return 0;
}