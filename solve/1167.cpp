// https://www.acmicpc.net/problem/1167

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int, int>

using namespace std;

int v;
vector<pii> tree[111'111];
bool visit[111'111];
int dist[111'111];

void dfs(int node)
{
    visit[node] = true;
    for (const auto& edge : tree[node])
    {
        if (!visit[edge.first])
        {
            visit[edge.first] = true;
            dist[edge.first] = dist[node] + edge.second;
            dfs(edge.first);
        }
    }
}

int findLongestNode(int start)
{
    for (int i = 0; i < 111'111; i++)
    {
        dist[i] = 0;
        visit[i] = false;
    }
    dfs(start);

    int longestDist = 0;
    int longestNode = 0;
    for (int i = 1; i <= v; i++)
    {
        if (longestDist < dist[i])
        {
            longestDist = dist[i];
            longestNode = i;
        }
    }
    return longestNode;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> v;
    for (int i = 1; i <= v; i++)
    {
        int node;
        cin >> node;
        while (true)
        {
            int next;
            cin >> next;
            if (next == -1) break;

            int weight;
            cin >> weight;

            tree[node].push_back({next, weight});
        }
    }

    int a = findLongestNode(1);
    int b = findLongestNode(a);
    cout << dist[b];
    return 0;
}