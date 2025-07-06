// https://www.acmicpc.net/problem/14890

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, l;
int map[111][111];
bool isElevated[111][111];

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < n))
        return false;
    return true;
}

void resetElevate()
{
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
        isElevated[y][x] = false;
}

bool elevate(int y, int x, int dy, int dx)
{
    // (y, x) ~ (y - dy*i, x - dx*i), i=(0,l) 까지 동일한 높이

    for (int i = 0; i < l; i++)
    {
        int py = y + dy * i;
        int px = x + dx * i;

        if (!canMove(py, px))
            return false;
        else if (isElevated[py][px])
            return false;
        else if (map[y][x] == map[py][px])
            isElevated[py][px] = true;
        else
            return false;
    }

    return true;
}

bool countToNext(int y, int x, int dy, int dx)
{
    int ny = y + dy;
    int nx = x + dx;
    if (!canMove(ny, nx))
        return true;

    int diff = map[ny][nx] - map[y][x];

    if (diff == 0)
    {
        return countToNext(ny, nx, dy, dx);
    }
    else if (diff == 1)
    {
        if (elevate(y, x, -dy, -dx))
            return countToNext(ny, nx, dy, dx);
        else
            return false;
    }
    else if (diff == -1)
    {
        if (elevate(ny, nx, dy, dx))
            return countToNext(ny, nx, dy, dx);
        else
            return false;
    }
    else
    {
        return false;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> l;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> map[y][x];
        }
    }

    int result = 0;

    resetElevate();
    for (int y = 0; y < n; y++)
    {
        if (countToNext(y, 0, 0, 1))
        {
            //cout << "row " << y << endl;
            result++;
        }
    }

    resetElevate();
    for (int x = 0; x < n; x++)
    {
        if (countToNext(0, x, 1, 0))
        {
            //cout << "col " << x << endl;
            result++;
        }
    }

    cout << result;
    return 0;
}