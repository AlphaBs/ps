// https://www.acmicpc.net/problem/8549

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
    int a, b, cost;
};

int n, m;
vector<int> map[111'111];
vector<Edge> edges;
int parent[111'111];

int findParent(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = findParent(parent[x]);
}

void merge(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

bool comp(const Edge& a, const Edge& b) 
{
    return a.cost < b.cost;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 111'111; i++)
    {
        parent[i] = i;
    }

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        Edge e = { a, b, cost };
        map[a].push_back(b);
        map[b].push_back(a);
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), comp);

    int lastCost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        Edge e = edges[i];
        if (findParent(e.a) != findParent(e.b))
        {
            merge(e.a, e.b);
            lastCost = e.cost;
        }
    }

    cout << lastCost;
    return 0;
}