// https://www.acmicpc.net/problem/2630

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// 파란색 1 true first
// 하얀색 0 false second
bool map[222][222];

pair<int, int> solve(int n, int y, int x)
{
    if (n == 1)
    {
        if (map[y][x])
            return make_pair(1, 0);
        else
            return make_pair(0, 1);
    }

    n /= 2;
    int blue = 0;
    int white = 0;

    int dx[] = { 0, 0, n, n };
    int dy[] = { 0, n, 0, n };

    for (int i = 0; i < 4; i++)
    {
        pair<int, int> part = solve(n, y + dy[i], x + dx[i]);
        blue += part.first;
        white += part.second;
    }

    if (blue == 4 && white == 0)
        blue = 1;
    if (blue == 0 && white == 4)
        white = 1;
    return make_pair(blue, white);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;    
    cin >> n;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        int v;
        cin >> v;
        map[y][x] = (v == 1);
    }

    pair<int, int> result = solve(n, 0, 0);
    cout << result.second << '\n' << result.first;
    return 0;
}