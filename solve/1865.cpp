// https://www.acmicpc.net/problem/1865

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 999'999'999;

struct Edge
{
    int u; int v; int w;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (--t >= 0)
    {
        int n, m, w, s, e, t;
        cin >> n >> m >> w;

        vector<Edge> edges;
        for (int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            edges.push_back({s,e,t});
            edges.push_back({e,s,t});
        }

        for (int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            edges.push_back({s,e,-t});
        }

        int dist[555];
        for (int i = 0; i < 555; i++)
            dist[i] = INF;
        dist[1] = 0;

        // 벨만포드 N-1회 반복 후 1번 더 반복해서 변화가 있는지 확인
        // 변화있으면 음수 사이클 존재
        bool updated = false;
        for (int i = 0; i < n; i++)
        {
            updated = false;
            for (const auto& edge : edges)
            {
                if (dist[edge.u] + edge.w < dist[edge.v])
                {
                    dist[edge.v] = dist[edge.u] + edge.w;
                    updated = true;
                }
            }
        }

        if (updated)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}