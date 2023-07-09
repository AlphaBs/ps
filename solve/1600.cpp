#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int oneDx[] = { -1, 0, 0, 1 };
int oneDy[] = { 0, -1, 1, 0 };
int horseDx[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int horseDy[] = { -2, -2, -1, -1, 1, 1, 2, 2 };

int k, w, h;
bool map[222][222];
bool visit[222][222][33];

struct MoveState
{
    int x;
    int y;
    int k;
    int step;
};

void printMap()
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            cout << (map[y][x] ? 1 : 0) << " ";
        }
        cout << "\n";
    }
}

bool canGo(int x, int y)
{
    if (x < 0 || y < 0)
        return false;
    if (x >= w || y >= h)
        return false;
    return map[y][x]; // !!!
}

int solve()
{
    int minStep = -1;
    std:queue<MoveState> q;
    q.push({ 0, 0, k, 0 });
    visit[0][0][k] = true;

    while (!q.empty())
    {
        MoveState state = q.front();
        q.pop();

        // if destination
        if (state.x == w - 1 && state.y == h - 1)
        {
            if (minStep == -1 || minStep > state.step)
                minStep = state.step;
            continue;
        }

        // one step
        for (int i = 0; i < 4; i++)
        {
            int newX = state.x + oneDx[i];
            int newY = state.y + oneDy[i];
            if (canGo(newX, newY) && !visit[newY][newX][state.k])
            {
                q.push({ newX, newY, state.k, state.step + 1 });
                visit[newY][newX][state.k] = true;
            }
        }

        if (state.k == 0)
            continue;

        // horse step
        for (int i = 0; i < 8; i++)
        {
            int newX = state.x + horseDx[i];
            int newY = state.y + horseDy[i];
            if (canGo(newX, newY) && !visit[newY][newX][state.k - 1])
            {
                q.push({ newX, newY, state.k - 1, state.step + 1});
                visit[newY][newX][state.k - 1] = true;
            }
        }
    }

    return minStep;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> w >> h;
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
    {
        int t;
        cin >> t;
        if (t == 0)
            map[y][x] = true;
        else
            map[y][x] = false;
    }

    int result = solve();
    cout << result;

    return 0;
}