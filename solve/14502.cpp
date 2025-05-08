// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define pii pair<int, int>

using namespace std;

int n, m; // 세로 n, 가로 m
int map[11][11];

int dy[4] = { 0,  0, 1, -1 };
int dx[4] = { 1, -1, 0,  0 };

void printMap()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cout << map[y][x] << ' ';
        }
        cout << endl;
    }
}

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < m))
        return false;
    return true;
}

int fillVirus(int y, int x)
{
    int n = 0;
    queue<pii> q;
    q.push({y, x});
    while (q.size())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        n++;

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (canMove(ny, nx) && map[ny][nx] == 0)
            {
                map[ny][nx] = 9;
                q.push({ny, nx});
            }
        }
    }
    return n;
}

int check()
{
    int safe = n * m;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == 1)
            {
                safe--;
            }
            else if (map[y][x] == 2)
            {
                safe -= fillVirus(y, x);
            }
        }
    }

    for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
    {
        if (map[y][x] == 9)
            map[y][x] = 0;
    }
    return safe;
}

int solve(int pos, int c)
{
    if (c == 0)
    {
        //printMap();
        //cout << endl;
        return check();
    }

    int ret = 0;
    for (int i = pos; i < n * m; i++)
    {
        int y = i / m;
        int x = i % m;

        if (map[y][x] == 0)
        {
            map[y][x] = 1;
            ret = max(ret, solve(i + 1, c - 1));
            map[y][x] = 0;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];
        }
    }

    cout << solve(0, 3);
    return 0;
}