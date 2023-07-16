// https://www.acmicpc.net/problem/10830

#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 6
#define MODER 1000

using namespace std;

long long n, b;
long long matrix[N][N];
long long ident[N][N];
long long multiplyResult[N][N];
long long powerResult[N][N];

void copyMatrix(long long src[N][N], long long dest[N][N])
{
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
        dest[y][x] = src[y][x];
}

// c = a * b
void multiply(long long m1[N][N], long long m2[N][N])
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            long long t = 0;
            for (int k = 0; k < n; k++)
            {
                t += ((m1[y][k] * m2[k][x]) % MODER);
            }
            multiplyResult[y][x] = t % MODER;
        }
    }
}

// b = a^p
void power(long long m[N][N], long long p)
{
    if (p == 0)
    {
        copyMatrix(ident, powerResult);
    }
    else if (p == 1)
    {
        copyMatrix(m, powerResult);
    }
    else if (p % 2 == 0)
    {
        power(m, p/2);
        multiply(powerResult, powerResult);
        copyMatrix(multiplyResult, powerResult);
    }
    else
    {
        power(m, p - 1);
        multiply(m, powerResult);
        copyMatrix(multiplyResult, powerResult);
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
                ident[y][x] = 1;
            cin >> matrix[y][x];
        }
    }

    power(matrix, b);

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            cout << (powerResult[y][x] % MODER) << " ";
        cout << "\n";
    }

    return 0;
}