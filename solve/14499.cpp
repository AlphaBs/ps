// https://www.acmicpc.net/problem/14499

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int E = 1;
const int W = 2;
const int N = 3;
const int S = 4;

int dice[10] = {};
int moveY[5] = { 0, 0,  0, -1, 1 };
int moveX[5] = { 0, 1, -1,  0, 0 };

int width;
int height;
int currentX;
int currentY;

int map[22][22];

bool canMove(int y, int x)
{
    if (!(0 <= y && y < height))
        return false;
    
    if (!(0 <= x && x < width))
        return false;

    return true;
}

void rollDice(int d)
{
    int tmp[10];

    if (d == N)
    {
        tmp[1] = dice[5];
        tmp[2] = dice[1];
        tmp[3] = dice[3];
        tmp[4] = dice[4];
        tmp[5] = dice[6];
        tmp[6] = dice[2];
    }
    if (d == S)
    {
        tmp[1] = dice[2];
        tmp[2] = dice[6];
        tmp[3] = dice[3];
        tmp[4] = dice[4];
        tmp[5] = dice[1];
        tmp[6] = dice[5];
    }
    if (d == E)
    {
        tmp[1] = dice[4];
        tmp[2] = dice[2];
        tmp[3] = dice[1];
        tmp[4] = dice[6];
        tmp[5] = dice[5];
        tmp[6] = dice[3];
    }
    if (d == W)
    {
        tmp[1] = dice[3];
        tmp[2] = dice[2];
        tmp[3] = dice[6];
        tmp[4] = dice[1];
        tmp[5] = dice[5];
        tmp[6] = dice[4];
    }

    dice[1] = tmp[1];
    dice[2] = tmp[2];
    dice[3] = tmp[3];
    dice[4] = tmp[4];
    dice[5] = tmp[5];
    dice[6] = tmp[6];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width >> currentY >> currentX;
    int k;
    cin >> k;

    for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++)
        cin >> map[y][x];

    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;

        int nextY = currentY + moveY[c];
        int nextX = currentX + moveX[c];

        if (!canMove(nextY, nextX))
            continue;

        rollDice(c);

        if (map[nextY][nextX] == 0)
            map[nextY][nextX] = dice[6];
        else
        {
            dice[6] = map[nextY][nextX];
            map[nextY][nextX] = 0;
        }

        currentY = nextY;
        currentX = nextX;
        cout << dice[1] << endl;
    }

    return 0;
}