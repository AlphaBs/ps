// https://www.acmicpc.net/problem/7573

#include <iostream>
#include <cstdio>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

// 2 <= n <= 10000
// 4 <= l <= 100
// 1 <= m <= 100
int n, l, m;
pii fish[111];

int countFish(int startY, int startX, int width, int height)
{
    int endY = startY + height;
    int endX = startX + width;

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int y = fish[i].first;
        int x = fish[i].second;

        if (startY <= y && y <= endY && startX <= x && x <= endX)
            count++;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> fish[i].first >> fish[i].second;
    }

    int maxResult = 0;
    for (int i = 0; i < m; i++)
    for (int w = 1; w < l / 2; w++)
    {
        int h = l / 2 - w;
        for (int dy = 0; dy < h; dy++)
        for (int dx = 0; dx < w; dx++)
        {
            int y = fish[i].first - dy;
            int x = fish[i].second - dx;
            if (y < 0 || x < 0) continue;

            int currentResult = countFish(y, x, w, h);
            maxResult = max(maxResult, currentResult);
        }
    }

    cout << maxResult;
    return 0;
}