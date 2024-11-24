// https://www.acmicpc.net/problem/1197

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define pii pair<int, int>
#define ll long long

using namespace std;

struct Edge
{
    ll a, b, c;
};

int v, e;
Edge edges[111'111];
int parent[111'111];

int findTree(int node)
{
    if (parent[node] == node)
        return parent[node];
    return parent[node] = findTree(parent[node]);
}

void unionTree(int a, int b)
{
    int fa = findTree(a);
    int fb = findTree(b);
    if (fa != fb)
        parent[fb] = fa;
}

bool comp(const Edge& a, const Edge& b)
{
    return a.c < b.c;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 11111; i++)
        parent[i] = i;

    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    sort(edges, edges + e, comp);

    ll total = edges[0].c;
    unionTree(edges[0].a, edges[0].b);
    for (int i = 1; i < e; i++)
    {
        if (findTree(edges[i].a) == findTree(edges[i].b))
            continue;
        total += edges[i].c;
        unionTree(edges[i].a, edges[i].b);
    }

    cout << total;
    return 0;
}