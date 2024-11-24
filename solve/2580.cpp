// https://www.acmicpc.net/problem/2580

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef int MAP[11][11];

void copyMap(MAP &src, MAP &dest)
{
    for (int y = 0; y < 9; y++)
        for (int x = 0; x < 9; x++)
        {
            dest[y][x] = src[y][x];
        }
}

void printMap(MAP &map)
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            cout << map[y][x] << ' ';
        }
        cout << '\n';
    }
}

pair<int, int> nextZero(MAP &map, int y, int x)
{
    for (; y < 9; y++)
    {
        while (x < 9)
        {
            if (map[y][x] == 0)
                return {y, x};
            x++;
        }
        x = 0;
    }
    return {-1,-1};
}

void fillMap(MAP &map, int y, int x)
{
    //printMap(map);
    //cout << endl;

    pair<int, int> pos = nextZero(map, y, x);
    y = pos.first;
    x = pos.second;

    if (y < 0 || x < 0)
    {
        printMap(map);
        exit(0);
    }

    bool numbers[11];
    for (int i = 1; i <= 9; i++)
        numbers[i] = true;

    MAP copy;
    copyMap(map, copy);

    int ySector = y / 3;
    int xSector = x / 3;

    for (int sy = 0; sy < 3; sy++)
        for (int sx = 0; sx < 3; sx++)
        {
            int v = map[ySector * 3 + sy][xSector * 3 + sx];
            numbers[v] = false;
        }

    for (int i = 0; i < 9; i++)
    {
        int vy = map[i][x];
        numbers[vy] = false;

        int vx = map[y][i];
        numbers[vx] = false;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (numbers[i])
        {
            copy[y][x] = i;
            fillMap(copy, y, x + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    MAP map;
    for (int y = 0; y < 9; y++)
        for (int x = 0; x < 9; x++)
        {
            cin >> map[y][x];
        }

    fillMap(map, 0, 0);
    return 0;
}