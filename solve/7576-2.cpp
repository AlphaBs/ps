// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits>
#include <queue>
#include <utility>

using namespace std;

//  1: 익음
//  0: 안익음
// -1: 빈칸
int width, height;
int map[1111][1111];
int depth[1111][1111];

int dy[4] = { 1, -1, 0,  0 };
int dx[4] = { 0,  0, 1, -1 };

bool canMove(int y, int x)
{
    if (!(0 <= y && y < height))
        return false;
    if (!(0 <= x && x < width))
        return false;
    
    // 안익은거 && 방문안한거
    return map[y][x] == 0 && depth[y][x] == 0;
}

void printDepth()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cout << depth[y][x] << ' ';
        }
        cout << endl;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int>> q;
    
    cin >> width >> height;
    for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++)
    {
        int v;
        cin >> v;
        map[y][x] = v;

        if (v == 1)
        {
            q.push(make_pair(y, x));
            depth[y][x] = 1;
        }
    }

    int maxDepth = 1;
    while (!q.empty())
    {
        pair<int, int> point = q.front(); q.pop();
        int y = point.first;
        int x = point.second;

        for (int i = 0; i < 4; i++)
        {
            if (canMove(y + dy[i], x + dx[i]))
            {
                q.push(make_pair(y + dy[i], x + dx[i]));
                int newDepth = depth[y][x] + 1;
                depth[y + dy[i]][x + dx[i]] = newDepth;
                maxDepth = max(maxDepth, newDepth);
            }
        }
    }

    bool isAllVisited = true;
    for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++)
    {
        // 빈칸아님 && 방문안함
        if (map[y][x] != -1 && depth[y][x] == 0)
            isAllVisited = false;
    }

    if (isAllVisited)
        cout << maxDepth - 1;
    else
        cout << -1;
    return 0;
}