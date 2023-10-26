// https://www.acmicpc.net/problem/1240

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int graph[1111][1111];
bool visited[1111];

int solve(int a, int b)
{
    //cout << a << " " << b << endl;
    if (a == b)
        return 0;

    int dist = 999'999;
    for (int i = 0; i < 1111; i++)
    {
        if (graph[a][i] && !visited[i])
        {
            visited[i] = true;
            dist = min(dist, solve(i, b) + graph[a][i]);
        }
    }
    return dist;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n-1; i++)
    {
        int a, b, dist;
        cin >> a >> b >> dist;
        graph[a][b] = graph[b][a] = dist;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < 1111; j++)
            visited[j] = false;
        visited[a] = true;

        cout << solve(a, b) << "\n";
    }

    return 0;
}