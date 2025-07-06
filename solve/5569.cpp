// https://www.acmicpc.net/problem/5569

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define TOP 0
#define RIGHT 1
#define MOD 100000

using namespace std;

int width, height;
int dp[111][111][5];

bool isTurnable(int state)
{
    return (state >> 1) & 1;
}

int getPreviousWay(int state)
{
    return state & 1;
}

int packState(int prevWay, bool turnable)
{
    return ((turnable ? 1 : 0) << 1) | (prevWay & 1);
}

int solve(int y, int x, int state)
{
    if (y > height || x > width)
        return 0;
    if (y == height && x == width)
        return 1;
    
    bool turnable = isTurnable(state);
    int prevWay = getPreviousWay(state);

    int& result = dp[y][x][state];
    if (result != -1)
        return result;
    result = 0;
    //cout << y << ", " << x << ", prev " << prevWay << ", turnable " << turnable << endl;

    // 방향바꾸기
    if (turnable && prevWay == TOP)
        result = (result + solve(y, x + 1, packState(RIGHT, false))) % MOD;
    if (turnable && prevWay == RIGHT)
        result = (result + solve(y + 1, x, packState(TOP, false))) % MOD;

    // 방향유지
    if (prevWay == TOP)
        result = (result + solve(y + 1, x, packState(TOP, true))) % MOD;
    if (prevWay == RIGHT)
        result = (result + solve(y, x + 1, packState(RIGHT, true))) % MOD;

    return result;
}

int main() 
{
    memset(dp, -1, sizeof(dp));

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> width >> height;
    int result = solve(1, 1, packState(TOP, false)) + solve(1, 1, packState(RIGHT, false));
    cout << result % MOD;

    return 0;
}