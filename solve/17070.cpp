// https://www.acmicpc.net/problem/17070

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int map[22][22];

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < n))
        return false;
    return map[y][x] == 0;
}

bool isDest(int y, int x)
{
    return y == (n - 1) && x == (n - 1);
}

// 0: 가로, 1: 세로, 2: 대각선
int solve(int y, int x, int state)
{
    if (isDest(y, x)) 
        return 1;

    int result = 0;
    if (state == 0)
    {
        if (isDest(y, x + 1))
            return 1;
        
        if (canMove(y, x + 2))
            result += solve(y, x + 1, 0);
        if (canMove(y, x + 2) && canMove(y + 1, x + 1) && canMove(y + 1, x + 2))
            result += solve(y, x + 1, 2);
    }
    if (state == 1)
    {
        if (isDest(y + 1, x))
            return 1;

        if (canMove(y + 2, x))
            result += solve(y + 1, x, 1);
        if (canMove(y + 2, x) && canMove(y + 2, x + 1) && canMove(y + 1, x + 1))
            result += solve(y + 1, x, 2);
    }
    if (state == 2)
    {
        if (isDest(y + 1, x + 1))
            return 1;

        if (canMove(y + 1, x + 2))
            result += solve(y + 1, x + 1, 0);
        if (canMove(y + 2, x + 1))
            result += solve(y + 1, x + 1, 1);
        if (canMove(y + 1, x + 2) && canMove(y + 2, x + 1) && canMove(y + 2, x + 2))
            result += solve(y + 1, x + 1, 2);
    }
    return result;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        cin >> map[y][x];
    }

    cout << solve(0, 0, 0);
    return 0;
}