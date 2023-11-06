// https://www.acmicpc.net/problem/10026

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
char map[111][111];
bool visited[111][111];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

bool isSameColor(char a, char b, bool isRG)
{
    if (isRG)
    {
        if (a == 'R')
            a = 'G';
        if (b == 'R')
            b = 'G';
    }
    
    return a == b;
}

void dfs(int y, int x, bool isRG)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (!visited[yy][xx] && isSameColor(map[y][x], map[yy][xx], isRG))
            dfs(yy, xx, isRG);
    }
}

void initVisited()
{
    for (int y = 0; y < 111; y++)
    for (int x = 0; x < 111; x++)
        visited[y][x] = false;
}

int countComponents(bool isRG)
{
    initVisited();

    int components = 0;
    for (int y = 1; y <= n; y++)
    for (int x = 1; x <= n; x++)
    {
        if (!visited[y][x])
        {
            components++;
            dfs(y, x, isRG);
        }
    }

    return components;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int y = 1; y <= n; y++)
    {
        string line;
        cin >> line;
        for (int x = 1; x <= n; x++)
        {
            map[y][x] = line[x - 1];
        }
    }

    cout << countComponents(false) << ' ' << countComponents(true) << '\n';
    return 0;
}