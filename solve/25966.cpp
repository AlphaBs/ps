// https://www.acmicpc.net/problem/25966

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, q;
int map[3333][3333];
int rowIndex[3333];

void swapRow(int i, int j)
{
    swap(rowIndex[i], rowIndex[j]);
}

int getValue(int y, int x)
{
    return map[rowIndex[y]][x];
}

void setValue(int y, int x, int k)
{
    map[rowIndex[y]][x] = k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> q;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];
        }

        rowIndex[y] = y;
    }

    for (int i = 0; i < q; i++)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 0)
        {
            int i, j, k;
            cin >> i >> j >> k;

            setValue(i, j, k);
        }
        else if (cmd == 1)
        {
            int i, j;
            cin >> i >> j;

            swapRow(i, j);
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cout << getValue(y, x) << ' ';
        }
        cout << '\n';
    }

    return 0;
}