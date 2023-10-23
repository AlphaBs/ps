// https://www.acmicpc.net/problem/1520

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int m, n;
int map[555][555];
int dp[555][555];
int dx[] = { 1, 0,-1, 0};
int dy[] = { 0, 1, 0,-1};

int solve(int y, int x)
{
    if (y == m - 1 && x == n - 1)
        return 1;
    if (y < 0 || y >= m || x < 0 || x >= n)
        return 0;
    
    int& res = dp[y][x];
    if (res != -1)
        return res;
    res = 0;
    
    for (int i = 0; i < 4; i++)
    {
        int next = map[y + dy[i]][x + dx[i]];
        if (map[y][x] > next)
            res += solve(y + dy[i], x + dx[i]);
    }
    return res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int y = 0; y < 555; y++)
    for (int x = 0; x < 555; x++)
        dp[y][x] = -1;

    cin >> m >> n;
    for (int y = 0; y < m; y++)
    for (int x = 0; x < n; x++)
        cin >> map[y][x];

    cout << solve(0,0) << "\n";
    return 0;
}