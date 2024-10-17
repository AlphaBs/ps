// https://www.acmicpc.net/problem/1197

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define INF 999'999'999
#define pii pair<int, int>

using namespace std;

int V, E;
vector<pii> graph[111'111];
bool visited[111'111];

int prim(int start)
{
    int mst = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        mst += w;

        for (const auto& edge : graph[u])
        {
            int v = edge.first;
            if (!visited[v])
                pq.push({edge.second, v});
        }
    }

    return mst;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout << prim(1);
    return 0;
}