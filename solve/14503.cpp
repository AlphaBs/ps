// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 0;
const int E = 1;
const int S = 2;
const int W = 3;

const int DIRTY = 0;
const int WALL = 1;
const int CLEAN = 2;

int width, height;
int x, y, d;
int map[55][55];

int moveY[4] = { -1, 0, 1,  0 };
int moveX[4] = {  0, 1, 0, -1 };

bool canMove(int yy, int xx)
{
    if (!(0 <= yy && yy < height))
        return false;
    if (!(0 <= xx && xx < width))
        return false;

    return true;
}

void printMap()
{
    cout << x << ',' << y << ' ' << d << endl;
    for (int yy = 0; yy < height; yy++)
    {
        for (int xx = 0; xx < width; xx++)
        {
            cout << map[yy][xx] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> height >> width;
    cin >> y >> x >> d;

    for (int yy = 0; yy < height; yy++)
    for (int xx = 0; xx < width; xx++)
    {
        cin >> map[yy][xx];
    }

    while (true)
    {
        map[y][x] = CLEAN;

        bool allClean = true;
        for (int i = 0; i < 4; i++)
        {
            int nextY = y + moveY[i];
            int nextX = x + moveX[i];

            if (canMove(nextY, nextX) && map[nextY][nextX] == DIRTY)
            {
                allClean = false;
                break;
            }
        }

        if (allClean) // 청소되지 않은 빈 칸이 없는 경우
        {
            int nextD;
            if (d == N) nextD = S;
            if (d == E) nextD = W;
            if (d == S) nextD = N;
            if (d == W) nextD = E;

            int nextY = y + moveY[nextD];
            int nextX = x + moveX[nextD];

            if (canMove(nextY, nextX) && map[nextY][nextX] != WALL) // 후진 가능
            {
                y = nextY; x = nextX;
                continue;
            }
            else // 후진 불가
            {
                break;
            }
        }
        else // 청소되지 않은 빈 칸이 있는 경우
        {
            int nextD;
            if (d == N) nextD = W;
            if (d == E) nextD = N;
            if (d == S) nextD = E;
            if (d == W) nextD = S;

            d = nextD;
            int nextY = y + moveY[d];
            int nextX = x + moveX[d];
            
            if (canMove(nextY, nextX) && map[nextY][nextX] == DIRTY)
            {
                y = nextY; x = nextX;
                continue;
            }
        }
    }

    int result = 0;
    for (int yy = 0; yy < height; yy++)
    for (int xx = 0; xx < width; xx++)
    {
        if (map[yy][xx] == CLEAN)
            result++;
    }

    //printMap();
    cout << result;
    return 0;
}