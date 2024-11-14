// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> edges[111'111];
bool visited[111'111];
int parent[111'111];

void solve(int start)
{
    for (const auto& next : edges[start])
    {
        if (!visited[next])
        {
            visited[next] = true;
            parent[next] = start;
            solve(next);
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, start;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    solve(1);
    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << '\n';
    }
    return 0;
}