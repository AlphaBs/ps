// https://www.acmicpc.net/problem/12100

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
typedef int MAP[22][22];

void copyMap(MAP &src, MAP &dest)
{
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        dest[y][x] = src[y][x];
    }
}

void printMap(MAP &map)
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cout << map[y][x] << ' ';
        }
        cout << endl;
    }
}

int getMap(MAP &map, int direction, int line, int pos)
{
    switch (direction)
    {
    case 0: // left
        return map[line][pos];
    case 1: // top
        return map[pos][line];
    case 2: // right
        return map[line][n - pos - 1];
    case 3: // bottom
        return map[n - pos - 1][line];
    }
    return 0;
}

int setMap(MAP &map, int direction, int line, int pos, int value)
{
    switch (direction)
    {
    case 0: // left
        return map[line][pos] = value;
    case 1: // top
        return map[pos][line] = value;
    case 2: // right
        return map[line][n - pos - 1] = value;
    case 3: // bottom
        return map[n - pos - 1][line] = value;
    }
    return 0;
}

void moveMap(MAP& map, int direction)
{
    bool used[22][22];
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
        used[y][x] = false;

    for (int line = 0; line < n; line++)
    {
        int lastPos = -1;
        int lastValue = -1;
        for (int pos = 0; pos < n; pos++)
        {
            int value = getMap(map, direction, line, pos);
            if (value > 0)
            {
                if (lastPos >= 0 && lastValue == value && !used[line][lastPos])
                {
                    lastValue *= 2;
                    setMap(map, direction, line, lastPos, lastValue);
                    used[line][lastPos] = true;
                    setMap(map, direction, line, pos, 0);
                }
                else
                {
                    lastPos++;
                    lastValue = value;
                    setMap(map, direction, line, pos, 0);
                    setMap(map, direction, line, lastPos, value);
                }
            }
        }
    }
}

int find(MAP& map, int count)
{
    if (count == 0)
    {
        int maxBlock = -1;
        for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            maxBlock = max(maxBlock, map[y][x]);
        return maxBlock;
    }

    MAP copy;
    int maxBlock = -1;
    for (int d = 0; d <= 3; d++)
    {
        copyMap(map, copy);
        moveMap(copy, d);
        maxBlock = max(maxBlock, find(copy, count - 1));
    }
    return maxBlock;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    MAP map;
    cin >> n;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        cin >> map[y][x];
    }
    cout << find(map, 5);
    return 0;
}