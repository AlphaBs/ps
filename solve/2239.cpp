// https://www.acmicpc.net/problem/2239

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

typedef int MAP[11][11];
MAP map;

void printMap()
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            cout << map[y][x];
        }
        cout << '\n';
    }
}

pair<int, int> findZero(int y, int x)
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
    return {-1, -1};
}

void solveMap(int y, int x)
{
    auto zero = findZero(y, x);
    y = zero.first; x = zero.second;

    if (y < 0 || x < 0)
    {
        printMap();
        exit(0);
    }

    bool numbers[10];
    for (int i = 1; i <= 9; i++)
        numbers[i] = true;

    int ySection = y / 3;
    int xSection = x / 3;

    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
        int v = map[ySection * 3 + i][xSection * 3 + j];
        numbers[v] = false;
    }

    for (int i = 0; i < 9; i++)
    {
        int vy = map[y][i];
        int vx = map[i][x];
        numbers[vy] = false;
        numbers[vx] = false;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (numbers[i])
        {
            map[y][x] = i;
            solveMap(y, x + 1);
        }
    }

    map[y][x] = 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int y = 0; y < 9; y++)
    {
        string line;
        cin >> line;
        for (int x = 0; x < 9; x++)
        {
            map[y][x] = line[x] - '0';
        }
    }

    solveMap(0, 0);
    return 0;
}