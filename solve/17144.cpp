// https://www.acmicpc.net/problem/17144

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int width, height;
int targetT;
int map[1111][1111];
int diffMap[1111][1111];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int upperFanY, upperFanX;
int lowerFanY, lowerFanX;

bool canMove(int y, int x)
{
    if (!(0 <= y && y < height))
        return false;
    if (!(0 <= x && x < width))
        return false;
    return true;
}

void spreadDust()
{
    memset(diffMap, 0, sizeof(diffMap));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (map[y][x] == -1)
                continue;

            int spreadCount = 0;
            int spreadAmount = map[y][x] / 5;
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (!canMove(ny, nx) || map[ny][nx] == -1)
                    continue;

                diffMap[ny][nx] += spreadAmount;
                spreadCount++;
            }
            diffMap[y][x] -= (spreadAmount * spreadCount);
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            map[y][x] += diffMap[y][x];
        }
    }
}

// (sy, sx) 에서 (dy, dx) 방향으로 길이가 length 인 라인을 (dy, dx) 방향으로 1칸 이동
void moveDustLine(int sy, int sx, int dy, int dx, int length)
{
    for (int i = length - 1; i >= 0; i--)
    {
        int currentY = sy + dy * i;
        int currentX = sx + dx * i;

        int nextY = currentY + dy;
        int nextX = currentX + dx;

        map[nextY][nextX] = map[currentY][currentX];
        map[currentY][currentX] = 0;
    }
}

void moveDust()
{
    // 위
    moveDustLine(0, upperFanX, 1, 0, upperFanY); // 상>하
    map[upperFanY][upperFanX] = -1; // 정화
    moveDustLine(0, width - 1, 0, -1, width - upperFanX - 1); // 우>좌
    moveDustLine(upperFanY, width - 1, -1, 0, upperFanY); // 하>상
    moveDustLine(upperFanY, upperFanX + 1, 0, 1, width - upperFanX - 2); // 좌>우

    // 아래
    moveDustLine(height - 1, lowerFanX, -1, 0, height - lowerFanY - 1); // 하>상
    map[lowerFanY][lowerFanX] = -1; // 정화
    moveDustLine(height - 1, width - 1, 0, -1, width - lowerFanX - 1); // 우>좌
    moveDustLine(lowerFanY, width - 1, 1, 0, height - lowerFanY - 1); // 상>하
    moveDustLine(lowerFanY, lowerFanX + 1, 0, 1, width - lowerFanX - 2); // 좌>우
}

int getTotalDust()
{
    int total = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (map[y][x] > 0)
                total += map[y][x];
        }
    }
    return total;
}

void printState()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cout << map[y][x] << ' ';
        }
        cout << endl;
    }
    cout << getTotalDust() << endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> height >> width >> targetT;
    int fan = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int v;
            cin >> v;
            map[y][x] = v;
            
            if (v == -1 && fan == 0)
                upperFanY = y, upperFanX = x, fan = 1;
            else if (v == -1 && fan == 1)
                lowerFanY = y, lowerFanX = x, fan = 2;
        }
    }

    for (int t = 0; t < targetT; t++)
    {
        spreadDust();
        //printState();
        moveDust();
        //printState();
    }

    cout << getTotalDust();
    return 0;
}