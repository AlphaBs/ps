// https://www.acmicpc.net/problem/13460

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 0;
const int E = 1;
const int S = 2;
const int W = 3;

const char BLANK = '.';
const char WALL = '#';
const char HOLE = 'O';
const char RED = 'R';
const char BLUE = 'B';

int dy[4] = { -1, 0, 1,  0 };
int dx[4] = {  0, 1, 0, -1 };

int width, height;
char map[11][11];
int depth[11][11][11][11];

struct State
{
    int redY, redX;
    int blueY, blueX;
};

int getDepth(State &state)
{
    return depth[state.redY][state.redX][state.blueY][state.blueX];
}

void setDepth(State &state, int d)
{
    depth[state.redY][state.redX][state.blueY][state.blueX] = d;
}

void printMap(State& state)
{
    cout << endl;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (state.blueY == y && state.blueX == x)
            {
                cout << BLUE;
            }
            else if (state.redY == y && state.redX == x)
            {
                cout << RED;
            }
            else
            {
                cout << map[y][x];
            }
        }
        cout << endl;
    }
}

bool moveBall(int &y, int &x, int direction)
{
    while (true)
    {
        int ny = y + dy[direction];
        int nx = x + dx[direction];

        if (map[ny][nx] == WALL)
        {
            return false;
        }
        if (map[ny][nx] == HOLE)
        {
            y = 0, x = 0;
            return true;
        }

        y = ny;
        x = nx;
    }

    return false;
}

bool moveBlue(State &state, int direction)
{
    map[state.redY][state.redX] = WALL;
    bool result = moveBall(state.blueY, state.blueX, direction);
    map[state.redY][state.redX] = BLANK;
    return result;
}

bool moveRed(State &state, int direction)
{
    map[state.blueY][state.blueX] = WALL;
    bool result = moveBall(state.redY, state.redX, direction);
    map[state.blueY][state.blueX] = BLANK;
    return result;
}

int search(State state)
{
    queue<State> q;
    q.push(state);
    setDepth(state, 1);

    while (!q.empty())
    {
        State current = q.front(); q.pop();
        int currentDepth = getDepth(current);

        if (currentDepth > 10)
            continue;

        for (int i = 0; i < 4; i++)
        {
            State next = current;
            bool endBlue = false;
            bool endRed = false;
            endBlue = endBlue || moveBlue(next, i);
            endRed = endRed || moveRed(next, i);
            endBlue = endBlue || moveBlue(next, i);
            endRed = endRed || moveRed(next, i);

            if (endBlue)
                continue;
            if (endRed)
                return currentDepth;

            if (getDepth(next) == 0)
            {
                setDepth(next, currentDepth + 1);
                q.push(next);
            }
        }
    }

    return -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> height >> width;

    State state;
    for (int y = 0; y < height; y++)
    {
        string line;
        cin >> line;

        for (int x = 0; x < width; x++)
        {
            if (line[x] == RED)
            {
                state.redY = y;
                state.redX = x;
                map[y][x] = BLANK;
            }
            else if (line[x] == BLUE)
            {
                state.blueY = y;
                state.blueX = x;
                map[y][x] = BLANK;
            }
            else
            {
                map[y][x] = line[x];
            }
        }
    }

    cout << search(state);
    return 0;
}