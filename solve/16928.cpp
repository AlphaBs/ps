#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define pii pair<int, int>

using namespace std;

int goUp[111];
int goDown[111];
int dist[111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        goUp[a] = b;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        goDown[a] = b;
    }

    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while (q.size())
    {
        int node = q.front();
        if (goUp[node] > 0)
            node = goUp[node];
        if (goDown[node] > 0)
            node = goDown[node];
        dist[node] = dist[q.front()];
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            if (node + i > 100)
                break;
            if (dist[node + i] == 0)
            {
                dist[node + i] = dist[node] + 1;
                q.push(node + i);
            }
        }
    }

    //for (int i = 1; i <= 100; i++)
    //{
    //    cout << i << ' ' << (dist[i] - 1) << '\n';
    //}

    cout << dist[100] - 1;
    return 0;
}