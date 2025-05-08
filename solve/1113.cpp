// https://www.acmicpc.net/problem/1113

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int width, height;
bool map[11][55][55]; // level, y, x
bool visit[55][55];
bool holeMap[55][55];

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, 1, -1, 0 };

bool isOutside(int y, int x)
{
    if (!(0 <= y && y < height))
        return true;
    if (!(0 <= x && x < width))
        return true;

    return false;
}

void resetVisit()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            visit[y][x] = false;
}

int fillWater(int level, int y, int x)
{
    if (visit[y][x])
        return -1;
    if (holeMap[y][x])
        return -1;

    int water = 1;
    visit[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (isOutside(ny, nx) || holeMap[ny][nx])
        {
            holeMap[y][x] = true;
            return -1;
        }

        if (visit[ny][nx])
        {
            continue;
        }

        if (!map[level][ny][nx])
        {
            int ret = fillWater(level, ny, nx);
            if (ret == -1)
            {
                holeMap[y][x] = true;
                return -1;
            }
            water += ret;
        }
    }

    return water;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;
    for (int y = 0; y < height; y++)
    {
        string line;
        cin >> line;
        for (int x = 0; x < width; x++)
        {
            int h = line[x] - '0';
            for (int level = 1; level <= h; level++)
                map[level][y][x] = true;
        }
    }

    int water = 0;
    
    for (int level = 1; level < 10; level++)
    {
        resetVisit();
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (!visit[y][x] && !map[level][y][x])
                {
                    int ret = fillWater(level, y, x);
                    if (ret > 0)
                    {
                        //cout << level << ',' << y << ',' << x << endl;
                        water += ret;
                    }
                }
            }
        }
    }

    cout << water;
    return 0;
}