// https://www.acmicpc.net/problem/2740

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int matrixA[111][111];
int matrixB[111][111];
int matrixC[111][111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;

    // n * m
    cin >> n >> m;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
        cin >> matrixA[y][x];

    // m * k
    cin >> m >> k;
    for (int y = 0; y < m; y++)
    for (int x = 0; x < k; x++)
        cin >> matrixB[y][x];

    // C = A * b
    for (int y = 0; y < n; y++)
    for (int x = 0; x < k; x++)
    for (int z = 0; z < m; z++)
        matrixC[y][x] += (matrixA[y][z] * matrixB[z][x]);

    // print
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < k; x++)
        {
            cout << matrixC[y][x] << " ";
        }
        cout << "\n";
    }

    return 0;
}