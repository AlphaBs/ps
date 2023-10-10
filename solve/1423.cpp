// https://www.acmicpc.net/problem/1423

#include <iostream>
#include <cstdio>
#include <algorithm>

#define LL long long

using namespace std;

LL n, d;
LL characters[55];
LL powers[55];
LL mem[55][111][111];
   
LL solve(int level, int upgraded, int remainDays)
{
    if (level == n)
        return 0;

    LL& res = mem[level][upgraded][remainDays];
    if (res != -1)
        return res;

    int currentCharacters = characters[level] + upgraded;
    int maxCount = min(currentCharacters, remainDays);
    for (int count = 0; count <= maxCount; count++)
    {
        LL nextPower = solve(level + 1, count, remainDays - count);
        LL currentPower = powers[level] * (currentCharacters - count);
        res = max(res, currentPower + nextPower);
    }
    return res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 55; i++)
    for (int j = 0; j < 111; j++)
    for (int k = 0; k < 111; k++)
        mem[i][j][k] = -1;

    cin >> n;
    for (LL i = 0; i < n; i++)
    {
        cin >> characters[i];
    }
    for (LL i = 0; i < n; i++)
    {
        cin >> powers[i];
    }
    cin >> d;

    cout << solve(0, 0, d) << endl;
    return 0;
}