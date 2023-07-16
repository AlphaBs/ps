// https://www.acmicpc.net/problem/10830

#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 6
#define MODER 1000

using namespace std;

long long n, b;
long long matrix[N][N];
long long result[N][N];
long long multiplyResult[N][N];

void copyMatrix(long long src[N][N], long long dest[N][N])
{
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
        dest[y][x] = src[y][x];
}

// m1 = m1 * m2
void multiplyMatrix(long long m1[N][N], long long m2[N][N])
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            multiplyResult[y][x] = 0;
            for (int k = 0; k < n; k++)
                multiplyResult[y][x] += (m1[y][k] * m2[k][x]);
            multiplyResult[y][x] %= MODER;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> b;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (x == y)
                result[y][x] = 1;
            cin >> matrix[y][x];
        }
    }

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            multiplyMatrix(result, matrix);
            copyMatrix(multiplyResult, result);
        }
        multiplyMatrix(matrix, matrix);
        copyMatrix(multiplyResult, matrix);
        b /= 2;
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cout << (result[y][x] % MODER) << " ";
        }
        cout << "\n";
    }

    return 0;
}