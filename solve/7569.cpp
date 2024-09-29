// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits>
#include <queue>
#include <utility>

using namespace std;

struct Point
{
    int z, y, x;
};

//  1: 익음
//  0: 안익음
// -1: 빈칸
int width, height, level;
int map[111][111][111];
int depth[111][111][111];

int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {0, 0, 0, 0, 1, -1};

bool canMove(int z, int y, int x)
{
    if (!(0 <= z && z < level))
        return false;
    if (!(0 <= y && y < height))
        return false;
    if (!(0 <= x && x < width))
        return false;

    // 안익은거 && 방문안한거
    return map[z][y][x] == 0 && depth[z][y][x] == 0;
}

void printDepth()
{
    for (int z = 0; z < level; z++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                cout << depth[y][x] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<Point> q;

    cin >> width >> height >> level;
    for (int z = 0; z < level; z++)
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
            {
                int v;
                cin >> v;
                map[z][y][x] = v;

                if (v == 1)
                {
                    q.push({z, y, x});
                    depth[z][y][x] = 1;
                }
            }

    int maxDepth = 1;
    while (!q.empty())
    {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            if (canMove(p.z + dz[i], p.y + dy[i], p.x + dx[i]))
            {
                q.push({p.z + dz[i], p.y + dy[i], p.x + dx[i]});
                int newDepth = depth[p.z][p.y][p.x] + 1;
                depth[p.z + dz[i]][p.y + dy[i]][p.x + dx[i]] = newDepth;
                maxDepth = max(maxDepth, newDepth);
            }
        }
    }

    bool isAllVisited = true;
    for (int z = 0; z < level; z++)
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
            {
                // 빈칸아님 && 방문안함
                if (map[z][y][x] != -1 && depth[z][y][x] == 0)
                    isAllVisited = false;
            }

    if (isAllVisited)
        cout << maxDepth - 1;
    else
        cout << -1;
    return 0;
}