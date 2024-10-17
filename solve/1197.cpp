// https://www.acmicpc.net/problem/1197

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
    int w, u, v;
};

int v, e;
Edge edges[111'111];
int parent[111'111];

bool wComparer(const Edge& a, const Edge& b)
{
    return a.w < b.w;
}

int findSet(int u)
{
    if (parent[u] != u)
        parent[u] = findSet(parent[u]);
    return parent[u];
}

void unionSet(int u, int v)
{
    int uRoot = findSet(u);
    int vRoot = findSet(v);
    if (uRoot != vRoot)
        parent[vRoot] = uRoot;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges, edges + e, wComparer);
    for (int i = 1; i <= v; i++)
        parent[i] = i;

    long long mstWeight = 0;
    int treeSize = 0;
    for (const auto& edge : edges)
    {
        if (findSet(edge.u) != findSet(edge.v))
        {
            unionSet(edge.u, edge.v);
            mstWeight += edge.w;
            treeSize++;
            if (treeSize == v - 1)
                break;
        }
    }
    cout << mstWeight;
    return 0;
}