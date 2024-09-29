// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N;
bool map[111][111];
bool visited[111];

int f(int node)
{
    int sum = 1;
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int current = q.front(); q.pop();
        for (int next = 0; next < 111; next++)
        {
            if (map[current][next] && !visited[next])
            {
                visited[next] = true;
                q.push(next);
                sum++;
            }
        }
    }
    return sum;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int pairs;
    cin >> pairs;
    for (int i = 0; i < pairs; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = map[y][x] = true;
    }

    cout << f(1) - 1 << endl;
    return 0;
}