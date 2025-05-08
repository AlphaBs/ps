#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
bool map[111][111];
bool visit[111];

void dfs(int start)
{
    for (int i = 0; i < n; i++)
    {
        if (map[start][i] && !visit[i])
        {
            visit[i] = true;
            dfs(i);
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        int v;
        cin >> v;
        if (v)
        {
            map[y][x] = true;
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int i = 0; i < n; i++)
            visit[i] = false;
        dfs(y);
        for (int x = 0; x < n; x++)
        {
            cout << (visit[x] ? 1 : 0) << ' ';
        }
        cout << '\n';
    }

    return 0;
}