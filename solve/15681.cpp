// https://www.acmicpc.net/problem/15681

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

const int MAX_SIZE = 111111;

using namespace std;

int n, r, q;
vector<int> tree[MAX_SIZE];
int sizes[MAX_SIZE];
bool visited[MAX_SIZE];

int initSize(int root)
{
    visited[root] = true;

    int sum = 1;
    for (int child : tree[root])
    {
        if (!visited[child])
            sum += initSize(child);
    }
    return sizes[root] = sum;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    initSize(r);

    for (int i = 0; i < q; i++)
    {
        int u;
        cin >> u;
        cout << sizes[u] << "\n";
    }

    return 0;
}