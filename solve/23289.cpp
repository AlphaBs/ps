// https://www.acmicpc.net/problem/23289

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int E = 1;
const int W = 2;
const int N = 3;
const int S = 4;

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

int width;
int height;
int k;
int choco;

int map[22][22];
bool wall[22][22][5];
int mapHeat[22][22];
int mapWeight[22][22];
bool visit[22][22];

void debugMap()
{
    return;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cout << mapHeat[y][x] << ' ';
        }
        cout << endl;
    }
    getchar();
}

bool canMove(int y, int x)
{
    if (!(0 <= y && y < height))
        return false;
    if (!(0 <= x && x < width))
        return false;
    return true;
}

void resetVisit()
{
    for (int y = 0; y < 22; y++)
        for (int x = 0; x < 22; x++)
            visit[y][x] = false;
}

void resetWeight()
{
    for (int y = 0; y < 22; y++)
        for (int x = 0; x < 22; x++)
            mapWeight[y][x] = 0;
}

int rotateLeftDirection(int from)
{
    switch (from)
    {
        case N: return W;
        case W: return S;
        case S: return E;
        case E: return N;
    }

    return from;
}

int rotateRightDirection(int from)
{
    switch (from)
    {
        case N: return E;
        case E: return S;
        case S: return W;
        case W: return N;
    }

    return from;
}

int oppositeDirection(int from)
{
    switch (from)
    {
        case N: return S;
        case S: return N;
        case E: return W;
        case W: return E;
    }

    return from;
}

void heat(int y, int x, int direction, int level)
{
    if (level == 0)
        return;
    if (!canMove(y, x))
        return;
    if (visit[y][x])
        return;

    visit[y][x] = true;
    mapHeat[y][x] += level;

    int opposite = oppositeDirection(direction);
    int frontY = y + dy[direction];
    int frontX = x + dx[direction];

    if (canMove(frontY, frontX) && !wall[y][x][direction])
        heat(frontY, frontX, direction, level - 1);

    int leftDirection = rotateLeftDirection(direction);
    int leftY = frontY + dy[leftDirection];
    int leftX = frontX + dx[leftDirection];

    if (canMove(leftY, leftX) && 
        !wall[y][x][leftDirection] && 
        !wall[leftY][leftX][opposite])
        heat(leftY, leftX, direction, level - 1);

    int rightDirection = rotateRightDirection(direction);
    int rightY = frontY + dy[rightDirection];
    int rightX = frontX + dx[rightDirection];

    if (canMove(rightY, rightX) && 
        !wall[y][x][rightDirection] && 
        !wall[rightY][rightX][opposite])
        heat(rightY, rightX, direction, level - 1);
}

void blowHeat()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            resetVisit();

            int direction = map[y][x];
            if (1 <= direction && direction <= 4)
            {
                int nextY = y + dy[direction];
                int nextX = x + dx[direction];

                heat(nextY, nextX, direction, 5);
            }
        }
}

void adjustHeat()
{
    resetWeight();
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            int leftY = y;
            int leftX = x + 1;
            int botY = y + 1;
            int botX = x;

            if (canMove(leftY, leftX) && !wall[y][x][E])
            {
                int d = abs(mapHeat[y][x] - mapHeat[leftY][leftX]) / 4;
                if (mapHeat[y][x] < mapHeat[leftY][leftX])
                {
                    mapWeight[y][x] += d;
                    mapWeight[leftY][leftX] -= d;
                }
                else
                {
                    mapWeight[y][x] -= d;
                    mapWeight[leftY][leftX] += d;
                }
            }

            if (canMove(botY, botX) && !wall[y][x][S])
            {
                int d = abs(mapHeat[y][x] - mapHeat[botY][botX]) / 4;
                if (mapHeat[y][x] < mapHeat[botY][botX])
                {
                    mapWeight[y][x] += d;
                    mapWeight[botY][botX] -= d;
                }
                else
                {
                    mapWeight[y][x] -= d;
                    mapWeight[botY][botX] += d;
                }
            }
        }

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            mapHeat[y][x] += mapWeight[y][x];
        }
}

void decreaseHeat(int y, int x)
{
    if (mapHeat[y][x] > 0)
        mapHeat[y][x] -= 1;
}

void decreaseOutsideHeat()
{
    for (int x = 0; x < width; x++)
    {
        decreaseHeat(0, x);
        decreaseHeat(height - 1, x);
    }
    for (int y = 1; y < height - 1; y++)
    {
        decreaseHeat(y, 0);
        decreaseHeat(y, width - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width >> k;

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            cin >> map[y][x];
            //cin >> mapHeat[y][x];
        }

    int w;
    cin >> w;

    for (int i = 0; i < w; i++)
    {
        int r, c, t;
        cin >> r >> c >> t;
        r--;
        c--;
        if (t == 0) // 위쪽 벽
        {
            wall[r][c][N] = true;
            if (r > 0)
                wall[r - 1][c][S] = true;
        }
        else // 오른쪽 벽
        {
            wall[r][c][E] = true;
            wall[r][c + 1][W] = true;
        }
    }

    // 온풍기
    while (true)
    {
        blowHeat();
        debugMap();

        adjustHeat();
        debugMap();

        decreaseOutsideHeat();
        debugMap();

        // 초코
        choco++;

        // 모든 칸의 온도가 K 이상인지 검사
        bool overK = true;
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
            {
                if (map[y][x] == 5)
                {
                    if (mapHeat[y][x] < k)
                    {
                        overK = false;
                        break;
                    }
                }
            }

        if (overK)
            break;

        if (choco == 101)
            break;
    }

    cout << choco;
    return 0;
}