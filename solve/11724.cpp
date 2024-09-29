// https://www.acmicpc.net/problem/11724

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
bool map[1'111][1'111];
bool visited[1'111];

void f(int node)
{
    visited[node] = true;
    for (int next = 1; next <= N; next++)
    {
        if (map[node][next] && !visited[next])
        {
            visited[next] = true;
            f(next);
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        map[u][v] = map[v][u] = true;
    }

    int sum = 0;
    for (int node = 1; node <= N; node++)
    {
        if (!visited[node])
        {
            f(node);
            sum++;
        }
    }

    cout << sum;
    return 0;
}