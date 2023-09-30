// https://www.acmicpc.net/problem/1301

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int ball[6];
long long mem[11][11][11][11][11][6][6];

long long solve(int pre1, int pre2, int b1, int b2, int b3, int b4, int b5)
{
    int sum = b1 + b2 + b3 + b4 + b5;
    if (sum == 0)
        return 1;

    long long& res = mem[b1][b2][b3][b4][b5][pre1][pre2];
    if (res != -1)
        return res;

    res = 0;
    if (pre1 != 1 && pre2 != 1 && b1 > 0)
    {
        res += solve(pre2, 1, b1-1, b2, b3, b4, b5);
    }
    if (pre1 != 2 && pre2 != 2 && b2 > 0)
    {
        res += solve(pre2, 2, b1, b2-1, b3, b4, b5);
    }
    if (pre1 != 3 && pre2 != 3 && b3 > 0)
    {
        res += solve(pre2, 3, b1, b2, b3-1, b4, b5);
    }
    if (pre1 != 4 && pre2 != 4 && b4 > 0)
    {
        res += solve(pre2, 4, b1, b2, b3, b4-1, b5);
    }
    if (pre1 != 5 && pre2 != 5 && b5 > 0)
    {
        res += solve(pre2, 5, b1, b2, b3, b4, b5-1);
    }
    return res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(mem, -1, sizeof(mem));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ball[i];
    }

    cout << solve(0, 0, ball[0], ball[1], ball[2], ball[3], ball[4]) << endl;
    return 0;
}