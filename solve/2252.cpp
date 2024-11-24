// https://www.acmicpc.net/problem/2252

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> dep[33333];
bool visit[33333];

void solve(int node)
{
    if (visit[node])
        return;
    visit[node] = true;

    for (auto& item : dep[node])
    {
        solve(item);
    }

    cout << node << ' ';
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dep[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}