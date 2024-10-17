// https://www.acmicpc.net/problem/1238

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 999'999'999;

int n, m, x;
int dist[1111][1111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 1111; i++)
    for (int j = 0; j < 1111; j++)
    {
        if (i == j) dist[i][j] = 0;
        else dist[i][j] = INF;
    }

    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int start, end, t;
        cin >> start >> end >> t;
        dist[start][end] = min(dist[start][end], t);
    }

    // floyd
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // find
    int maxDist = -1;
    for (int i = 1; i <= n; i++)
    {
        maxDist = max(maxDist, dist[i][x] + dist[x][i]);
    }
    cout << maxDist;
    return 0;
}