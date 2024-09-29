// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
bool map[111][111];
bool visited[111];

int f(int node)
{
    int sum = 1;
    visited[node] = true;
    for (int next = 0; next < 111; next++)
    {
        if (map[node][next] && !visited[next])
        {
            visited[next] = true;
            sum += f(next);
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