// https://www.acmicpc.net/problem/4485

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 999'999
#define pii pair<int, int>
#define pw pair<int, pii>

using namespace std;

int n;
int map[222][222];
int dist[222][222];

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool canMove(const pii &p)
{
    if (!(0 <= p.first && p.first < n))
        return false;
    if (!(0 <= p.second && p.second < n))
        return false;
    return true;
}

int getMap(const pii &p)
{
    return map[p.first][p.second];
}

int getDist(const pii &p)
{
    return dist[p.first][p.second];
}

void setDist(const pii &p, int v)
{
    dist[p.first][p.second] = v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int th = 0;
    while (true)
    {
        th++;

        cin >> n;
        if (n == 0) break;

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                cin >> map[y][x];
                setDist({y, x}, INF);
            }
        }

        setDist({0, 0}, getMap({0, 0}));
        priority_queue<pw, vector<pw>, greater<pw>> pq;
        pq.push({getMap({0, 0}), {0, 0}});
        while (!pq.empty())
        {
            int cost = pq.top().first;
            pii now = pq.top().second;
            pq.pop();

            if (getDist(now) < cost)
                continue;

            for (int i = 0; i < 4; i++)
            {
                pii next = {now.first + dy[i], now.second + dx[i]};
                if (canMove(next))
                {
                    int nextCost = cost + getMap(next);
                    if (getDist(next) > nextCost)
                    {
                        setDist(next, nextCost);
                        pq.push({nextCost, next});
                    }
                }
            }
        }

        printf("Problem %d: %d\n", th, getDist({n-1, n-1}));
    }
    return 0;
}