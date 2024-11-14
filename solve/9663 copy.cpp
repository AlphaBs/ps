// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// 0: 빈칸, -1: 퀸, 이외 못가는곳
int n, result;
int map[22][22];

void printMap()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            //cout << (char)(map[y][x] == -1 ? 'X' : (map[y][x] + '0')) << ' ';
            cout << (char)(map[y][x] == -1 ? 'X' : '-') << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void addMap(int y, int x, int d)
{
    if (!(0 <= y && y < n))
        return;
    if (!(0 <= x && x < n))
        return;

    map[y][x] += d;
}

void addQueen(int y, int x, int d)
{
    for (int i = 0; i < n; i++)
    {
        addMap(y, i, d);
        addMap(i, x, d);
        addMap(i + y - x, i, d);
        addMap(-i + x + y, i, d);
    }
}

void find(int startY, int startPos, int q)
{
    if (q == n)
    {
        //printMap();
        result++;
        return;
    }

    for (int y = startY; y < n; y++)
        for (int x = 0; x < n; x++)
        {
            int pos = y * n + x;
            if (map[y][x] == 0 && startPos <= pos)
            {
                addQueen(y, x, 1);
                map[y][x] = -1;
                find(y + 1, pos + 1, q + 1);
                addQueen(y, x, -1);
                map[y][x] = 0;
            }
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    find(0, 0, 0);
    cout << result;
    return 0;
}