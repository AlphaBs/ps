// https://www.acmicpc.net/problem/1753

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int v, e, k;
vector<pair<int, int>> graph[22'222];
priority_queue<pair<int, int>> pq;
int dist[22'222];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 22'222; i++)
        dist[i] = INF;

    cin >> v >> e >> k;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // weight, node
    pq.push({0, k});
    dist[k] = 0;

    while (!pq.empty())
    {
        int d = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < d)
            continue;

        for (const auto& edge : graph[node])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({-dist[v], v});
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
    return 0;
}