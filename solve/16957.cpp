// https://www.acmicpc.net/problem/16957

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Point 
{
    int y, x;
};

int width, height;
int map[555][555];
int ball[555][555];
Point dp[555][555];

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool canMove(int y, int x)
{
    if (!(0 <= y && y < height))
        return false;
    if (!(0 <= x && x < width))
        return false;
    return true;
}

Point move(int y, int x)
{
    Point& result = dp[y][x];
    if (result.y != -1)
        return result;

    int current = map[y][x];
    int minMap = 999'999;
    int minY, minX;

    for (int i = 0; i < 8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (canMove(ny, nx) && minMap > map[ny][nx])
        {
            minMap = map[ny][nx];
            minY = ny;
            minX = nx;
        }
    }

    if (minMap > current)
    {
        return result = { y, x };
    }
    else
    {
        return result = move(minY, minX);
    }
}

int main() 
{
    for (int y = 0; y < 555; y++)
    for (int x = 0; x < 555; x++)
    {
        dp[y][x] = { -1, -1 };
    }

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> height >> width;
    for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++)
    {
        cin >> map[y][x];
    }

    for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++)
    {
        Point p = move(y, x);
        ball[p.y][p.x]++;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cout << ball[y][x] << ' ';
        }
        cout << '\n';
    }

    return 0;
}