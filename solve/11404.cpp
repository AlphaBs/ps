// https://www.acmicpc.net/problem/11404

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 111'111'111;
int dist[111][111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int y = 0; y < 111; y++)
    for (int x = 0; x < 111; x++)
    {
        if (x == y)
            dist[y][x] = 0;
        else
            dist[y][x] = INF;
    }

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] < INF)
                cout << dist[i][j] << ' ';
            else
                cout << "0 ";
        }
        cout << '\n';
    }

    return 0;
}