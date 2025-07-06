// https://www.acmicpc.net/problem/15683

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define N 0
#define E 1
#define S 2
#define W 3

using namespace std;

struct Monitor
{
    int y, x;
    int type;
    int direction;
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int width, height;
bool wall[11][11];
vector<Monitor> monitors;
bool visible[11][11];

bool canMove(int y, int x)
{
    if (!(0 <= y && y < height))
        return false;
    if (!(0 <= x && x < width))
        return false;
    return true;
}

void resetVisible()
{
    for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++)
        visible[y][x] = false;
}

void fillVisibleArea(int y, int x, int dy, int dx)
{
    while (canMove(y, x) && !wall[y][x])
    {
        visible[y][x] = true;
        y += dy;
        x += dx;
    }
}

void fillMonitoredArea()
{
    for (auto& monitor : monitors)
    {
        if (monitor.type == 1)
        {
            fillVisibleArea(
                monitor.y, 
                monitor.x, 
                dy[monitor.direction], 
                dx[monitor.direction]);
        }
        else if (monitor.type == 2)
        {
            if (monitor.direction == N || monitor.direction == S)
            {
                fillVisibleArea(
                    monitor.y,
                    monitor.x,
                    dy[N],
                    dx[N]);
                fillVisibleArea(
                    monitor.y,
                    monitor.x,
                    dy[S],
                    dx[S]);
            }
            if (monitor.direction == E || monitor.direction == W)
            {
                fillVisibleArea(
                    monitor.y,
                    monitor.x,
                    dy[E],
                    dx[E]);
                fillVisibleArea(
                    monitor.y,
                    monitor.x,
                    dy[W],
                    dx[W]);
            }
        }
        else if (monitor.type == 3)
        {
            fillVisibleArea(
                monitor.y, 
                monitor.x, 
                dy[monitor.direction], 
                dx[monitor.direction]);

            int nextDirection = (monitor.direction + 1) % 4;
            fillVisibleArea(
                monitor.y, 
                monitor.x, 
                dy[nextDirection], 
                dx[nextDirection]);
        }
        else if (monitor.type == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                if (i == monitor.direction)
                    continue;

                fillVisibleArea(
                    monitor.y, 
                    monitor.x, 
                    dy[i], 
                    dx[i]);
            }
        }
        else if (monitor.type == 5)
        {
            for (int i = 0; i < 4; i++)
            {
                fillVisibleArea(
                    monitor.y, 
                    monitor.x, 
                    dy[i], 
                    dx[i]);
            }
        }
    }
}

int countInvisibleAreas()
{
    int invisibleAreas = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (!visible[y][x] && !wall[y][x])
            {
                invisibleAreas++;
                //cout << "# ";
            }
            else 
            {
                //cout << "- ";
            }
        }
        //cout << endl;
    }
    //cout << invisibleAreas << endl;
    return invisibleAreas;
}

int find(int monitorIndex)
{
    // 모든 CCTV 설정완료
    if (monitorIndex == monitors.size())
    {
        resetVisible();
        fillMonitoredArea();
        return countInvisibleAreas();
    }

    int result = 999'999'999;
    for (int i = 0; i < 4; i++)
    {
        monitors[monitorIndex].direction = i;
        result = min(result, find(monitorIndex + 1));
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> height >> width;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            wall[y][x] = false;

            int v;
            cin >> v;
            
            if (v == 6)
                wall[y][x] = true;
            else if (v != 0)
            {
                Monitor monitor;
                monitor.y = y;
                monitor.x = x;
                monitor.type = v;
                monitor.direction = N;
                monitors.push_back(monitor);
            }
        }
    }

    cout << find(0);
    return 0;
}