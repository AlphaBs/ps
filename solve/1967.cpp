// https://www.acmicpc.net/problem/1967

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int, int>

using namespace std;

int n;
vector<pii> graph[11111];
bool visited[11111];
int dist[11111];

void findDist(int start)
{
    visited[start] = true;
    for (const auto& edge : graph[start])
    {
        int next = edge.first;
        int weight = edge.second;
        
        if (!visited[next])
        {
            dist[next] = dist[start] + weight;
            findDist(next);
        }
    }
}

int findMax(int start)
{
    for (int i = 0; i < 11111; i++)
    {
        visited[i] = false;
        dist[i] = 0;
    }

    findDist(start);

    int maxDist = 0;
    int node = start;
    
    for (int i = 1; i <= n; i++)
    {
        if (maxDist < dist[i])
        {
            maxDist = dist[i];
            node = i;
        }
    }

    return node;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p, c, w;
        cin >> p >> c >> w;
        graph[p].push_back({c, w});
        graph[c].push_back({p, w});
    }

    int a = findMax(1);
    int b = findMax(a);
    cout << dist[b];
    return 0;
}