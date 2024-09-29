// https://www.acmicpc.net/problem/14940

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

// -2: 갈수없는곳, -1: 방문안한곳, 0: 목표지점, >0 방문한곳
int map[1111][1111];
int width, height;
int dy[] = { 1, -1, 0,  0 };
int dx[] = { 0,  0, 1, -1 };

bool canMove(int y, int x)
{
    if (0 <= y && y < height && 0 <= x && x < width)
    {
        if (map[y][x] == -1)
            return true;
    }
    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int>> q;
    cin >> height >> width;

    for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++)
    {
        int v;
        cin >> v;
        map[y][x] = v - 2;
        if (v == 2)
            q.push(make_pair(y, x));
    }

    while (!q.empty())
    {
        pair<int, int> point = q.front(); q.pop();
        int y = point.first;
        int x = point.second;

        for (int i = 0; i < 4; i++)
        {
            if (canMove(y + dy[i], x + dx[i]))
            {
                map[y + dy[i]][x + dx[i]] = map[y][x] + 1;
                q.push(make_pair(y + dy[i], x + dx[i]));
            }
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (map[y][x] == -2)
                cout << "0 ";
            else
                cout << map[y][x] << ' ';
        }
        cout << endl;
    }

    return 0;
}