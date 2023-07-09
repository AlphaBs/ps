// https://www.acmicpc.net/problem/1149

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int nc;
int mem[1111][3];
int values[1111][3];

int const R = 0;
int const G = 1;
int const B = 2;

int fill(int n, int rgb)
{
    if (mem[n][rgb] >= 0)
        return mem[n][rgb];
    if (n >= nc)
        return mem[n][rgb] = values[n][rgb];
 
    int minValue = 999'999'999;
    for (int i = R; i <= B; i++)
    {
        if (i == rgb)
            continue;
        minValue = min(minValue, fill(n + 1, i));
    }
    return mem[n][rgb] = (values[n][rgb] + minValue);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 1111; i++)
    for (int j = 0; j < 3; j++)
        mem[i][j] = -1;

    cin >> nc;
    for (int i = 0; i < nc; i++)
    {
        cin >> values[i+1][R] >> values[i+1][G] >> values[i+1][B];
    }

    int minValue = fill(1, R);
    minValue = min(minValue, fill(1, G));
    minValue = min(minValue, fill(1, B));
    cout << minValue;

    return 0;
}