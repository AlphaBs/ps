// https://www.acmicpc.net/problem/14500

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int tets[4][3][3] = 
{
    {
        { 0, 1, 0 },
        { 1, 1, 1 },
        { 0, 0, 0 },
    },
    {
        { 0, 1, 0 },
        { 0, 1, 1 },
        { 0, 1, 0 },
    },
    {
        { 0, 0, 0 },
        { 1, 1, 1 },
        { 0, 1, 0 },
    },
    {
        { 0, 1, 0 },
        { 1, 1, 0 },
        { 0, 1, 0 },
    },
};

int n, m;
int map[555][555];
bool visit[555][555];

int dy[] = { 0,  0,  1, -1 };
int dx[] = { 1, -1,  0,  0 };

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < m))
        return false;
    return true;
}

int fillMap(int sy, int sx, int c)
{
    if (c == 0)
        return 0;
    
    visit[sy][sx] = true;
    int maxNext = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = sy + dy[i];
        int nx = sx + dx[i];

        if (!visit[ny][nx] && canMove(ny, nx))
            maxNext = max(maxNext, fillMap(ny, nx, c - 1));
    }
    visit[sy][sx] = false;
    return maxNext + map[sy][sx];
}

int fillTets(int sy, int sx, int i)
{
    // (1, 1)
    int r = 0;
    for (int y = 0; y < 3; y++)
    for (int x = 0; x < 3; x++)
    {
        int ny = sy + y - 1;
        int nx = sx + x - 1;
        if (tets[i][y][x] == 1)
        {
            if (!canMove(ny, nx))
                return 0;
            r += map[ny][nx];
        }
    }
    return r;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
    {
        cin >> map[y][x];
    }

    int maxResult = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            maxResult = max(maxResult, fillMap(y, x, 4));
            for (int i = 0; i < 4; i++)
            {
                maxResult = max(maxResult, fillTets(y, x, i));
            }
            //cout << maxResult << ' ';
        }
        //cout << '\n';
    }

    cout << maxResult;
    return 0;
}