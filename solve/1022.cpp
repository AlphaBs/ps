#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int intlen(int n)
{
    return to_string(n).length();
}

int calcLen(int n)
{
    return 2 * n + 1;
}

int calcYX(int n)
{
    if (n > 0)
    {
        int len = calcLen(n);
        return len * len;
    }
    else if (n < 0)
    {
        int len = calcLen(-n);
        return len * len - 2 * (len - 1);
    }
    else
    {
        return 1;
    }
}

int solve(int y, int x)
{
    if (abs(y) >= abs(x) && y > 0)
        return calcYX(y) + (x - y);
    else if (abs(y) < abs(x) && x > 0)
        return calcYX(x - 1) + (x - y);
    else if (abs(y) >= abs(x) && y < 0)
        return calcYX(y) + (y - x);
    else if (abs(y) < abs(x) && x < 0)
        return calcYX(x) + (y - x);
    else
        return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;

    int width = x2 - x1 + 1;
    int height = y2 - y1 + 1;

    int maxNum = -1;
    int maxLength = 1;

    int map[55][5];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            map[y][x] = solve(y1 + y, x1 + x);
            maxNum = max(maxNum, map[y][x]);
        }
    }
    maxLength = intlen(maxNum);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int i = 0; i < maxLength - intlen(map[y][x]); i++)
                cout << ' ';

            cout << map[y][x] << " ";
        }
        cout << '\n';
    }

    return 0;
}