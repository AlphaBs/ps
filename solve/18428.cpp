// https://www.acmicpc.net/problem/18428

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int map[11][11]; // 0 없음 1 선생 2 학생 3 벽

int dy[] = { 1, -1, 0,  0 };
int dx[] = { 0,  0, 1, -1 };

void printMap()
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

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < n))
        return false;
    return true;
}

bool verify()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (map[y][x] == 1)
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 1; j < n; j++)
                    {
                        int ny = y + dy[i] * j;
                        int nx = x + dx[i] * j;
                        if (!canMove(ny, nx))
                            break;
                        if (map[ny][nx] == 2)
                            return false;
                        if (map[ny][nx] == 3)
                            break;
                    }
                }
            }
        }
    }

    return true;
}

bool find(int y, int x, int o)
{
    if (o == 0)
    {
        return verify();
    }

    while (y < n)
    {
        int nx = x + 1;
        int ny = y;

        if (nx == n)
        {
            nx = 0;
            ny++;
        }

        if (map[y][x] == 0)
        {
            map[y][x] = 3;
            bool result = find(ny, nx, o - 1);
            if (result)
                return true;
            map[y][x] = 0;
        }

        y = ny;
        x = nx;
    }

    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        char c;
        cin >> c;
        if (c == 'S')
            map[y][x] = 2;
        else if (c == 'T')
            map[y][x] = 1;
        else
            map[y][x] = 0;
    }

    bool result = find(0, 0, 3);
    if (result)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}