// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int src, dest;
bool visited[111'111];
int depth[111'111];

bool visit(int from, int d)
{
    int to = from + d;
    if (0 <= to && to <= 100'000 && !visited[to])
    {
        visited[to] = true;
        depth[to] = depth[from] + 1;
        return true;
    }
    else
        return false;
}

int f(int node)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        node = q.front(); q.pop();

        if (node == dest)
            return depth[node];

        if (visit(node, 1))
            q.push(node + 1);
        if (visit(node, -1))
            q.push(node - 1);
        if (visit(node, node))
            q.push(node * 2);
    }

    return 999'999'999;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> src >> dest;
    cout << f(src);
    return 0;
}