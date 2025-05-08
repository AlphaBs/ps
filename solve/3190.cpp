// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 0;
const int E = 1;
const int S = 2;
const int W = 3;

int moveY[4] = { -1, 0, 1,  0 };
int moveX[4] = {  0, 1, 0, -1 };

int n, k;

bool play = true;
int currentD = E;
int currentT = 1;

bool apple[111][111];
int snake[111][111];

void printMap()
{
    return;
    cout << currentT << ' ' << currentD << endl;
    for (int y = 0; y < n; y++)
    {
        cout << '*';
        for (int x = 0; x < n; x++)
        {
            if (apple[y][x])
                cout << '@';
            else if (snake[y][x] > 0)
                cout << '#';
                //cout << snake[y][x];
            else
                cout << ' ';
        }
        cout << '*';
        cout << endl;
    }
}

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < n))
        return false;
    return true;
}

bool move()
{
    int maxCell = -1;
    int minCell = 999'999'999;

    int headX, headY;
    int tailX, tailY;

    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        if (snake[y][x] == 0)
            continue;

        if (snake[y][x] < minCell)
        {
            minCell = snake[y][x];
            tailY = y; tailX = x;
        }
        if (snake[y][x] > maxCell)
        {
            maxCell = snake[y][x];
            headY = y; headX = x;
        }
    }

    int nextY = headY + moveY[currentD];
    int nextX = headX + moveX[currentD];

    if (!canMove(nextY, nextX))
        return false;

    if (snake[nextY][nextX] > 0)
        return false;
    
    snake[nextY][nextX] = maxCell + 1;

    if (apple[nextY][nextX])
    {
        apple[nextY][nextX] = false;
        return true;
    }
    else
    {
        snake[tailY][tailX] = 0;
        return true;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    snake[0][0] = 1;

    cin >> n >> k;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        apple[y][x] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        apple[y - 1][x - 1] = 1;
    }

    int l;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int x; cin >> x;
        char c; cin >> c;

        for (; currentT <= x; currentT++)
        {
            play = move();
            printMap();
            if (!play)
            {
                cout << currentT;
                return 0;
            }
        }

        if (c == 'L')
        {
            currentD = (currentD + 3) % 4;
        }
        if (c == 'D')
        {
            currentD = (currentD + 1) % 4;
        }
    }

    for (;;currentT++)
    {
        play = move();
        printMap();
        if (!play)
        {
            cout << currentT;
            return 0;
        }
    }
}