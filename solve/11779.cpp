// https://www.acmicpc.net/problem/11779

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 999'999'999
#define pii pair<int, int>

using namespace std;

int n, m;
vector<pii> adj[111'111];
int dist[111'111];
int parent[111'111];

void dijkstra(int start)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost > dist[now])
            continue;

        for (const auto& edge : adj[now])
        {
            int next = edge.first;
            int w = edge.second;

            if (dist[next] > cost + w)
            {
                dist[next] = cost + w;
                pq.push({cost + w, next});
                parent[next] = now;
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 111'111; i++)
        dist[i] = INF;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;
    dijkstra(start);

    vector<int> route;
    int c = end;
    while (c != 0)
    {
        route.push_back(c);
        c = parent[c];
    }

    cout << dist[end] << '\n' << route.size() << '\n';
    for (int i = route.size() - 1; i >= 0; i--)
    {
        cout << route[i] << ' ';
    }

    return 0;
}