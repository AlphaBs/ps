// https://www.acmicpc.net/problem/1025

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int h, w;
int map[11][11];
int numbers[11];

int numbersToInt(int length)
{
    int number = 0;
    int powered = 1;
    for (int i = 0; i < length; i++)
    {
        number += (numbers[i] * powered);
        powered *= 10;
    }
    return number;
}

int numbersToIntReverse(int length)
{
    int number = 0;
    int powered = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        number += (numbers[i] * powered);
        powered *= 10;
    }
    return number;
}

bool isSquare(unsigned int n)
{
    unsigned int sq = (unsigned int)sqrt((double)n);
    return (n == sq * sq);
}

bool canGo(int x, int y)
{
    if (x < 0 || y < 0)
        return false;
    if (x >= w || y >= h)
        return false;
    return true;
}

int findMax(int x, int y)
{
    // Xn = x + a*n, Yn = y + b*n
    int maxResult = -1;
    if (isSquare(map[y][x]))
        maxResult = map[y][x];

    for (int a = 0; a < w; a++)
        for (int b = -h + 1; b < h; b++)
        // for (int a = 1; a == 1; a++)
        // for (int b = 0; b == 0; b++)
        {
            if (a == 0 && b == 0)
                continue;

            // cout << x << "," << y << " " << a << "," << b << " : ";

            int n = 0;
            while (true)
            {
                int xn = x + a * n;
                int yn = y + b * n;

                if (!canGo(xn, yn))
                    break;

                numbers[n] = map[yn][xn];
                n++;

                int num1 = numbersToInt(n);
                int num2 = numbersToIntReverse(n);

                if (!isSquare(num1))
                    num1 = -1;
                if (!isSquare(num2))
                    num2 = -1;

                // cout << num1 << "," << num2 <<"\n";
                maxResult = max(maxResult, max(num1, num2));
            }
        }
    return maxResult;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for (int y = 0; y < h; y++)
    {
        std::string line;
        cin >> line;
        for (int x = 0; x < w; x++)
        {
            map[y][x] = line[x] - '0';
        }
    }

    int maxResult = -1;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
        {
            maxResult = max(maxResult, findMax(x, y));
        }
    cout << maxResult;

    return 0;
}