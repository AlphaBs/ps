// https://www.acmicpc.net/problem/25187

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, q;
int isCleanWater[111'111];
int parent[111'111];

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        parent[u] = v;
    }
}

int main() 
{
    for (int i = 0; i < 111'111; i++)
    {
        parent[i] = i;
    }

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            isCleanWater[i]++;
        else
            isCleanWater[i]--;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }

    for (int i = 1; i <= n; i++)
    {
        int root = find(i);
        if (root != i)
            isCleanWater[root] += isCleanWater[i];
    }

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        int root = find(k);
        //cout << isCleanWater[root] << '\n';
        cout << (isCleanWater[root] > 0 ? '1' : '0') << '\n';
    }

    return 0;
}