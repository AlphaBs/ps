// https://www.acmicpc.net/problem/16954

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_set>

#define SIZE 8
#define MAP unsigned long long

using namespace std;

unordered_set<MAP> visited[SIZE][SIZE];

int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool getMap(MAP& map, int y, int x)
{
    int index = y * SIZE + x;
    MAP mask = 1ULL << index;
    return (map & mask) != 0;
}

void setMap(MAP& map, int y, int x, bool value)
{
    int index = y * SIZE + x;
    MAP mask = 1ULL << index;
    if (value)
    {
        map = map | mask;
    }
    else
    {
        map = map & (~mask);
    }
}

void printMap(MAP& map)
{
    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            bool v = getMap(map, y, x);
            cout << (v ? '#' : '.');
        }
        cout << endl;
    }
}

bool canMove(int y, int x)
{
    if (!(0 <= y && y < SIZE))
        return false;
    if (!(0 <= x && x < SIZE))
        return false;
    return true;
}

void moveWalls(MAP& map)
{
    // 제일 아래 벽은 삭제
    for (int x = 0; x < SIZE; x++)
        setMap(map, SIZE - 1, x, false);

    // 6 5 4 3 2 1 0 순으로 이동
    for (int y = 6; y >= 0; y--)
    {
        for (int x = 0; x < SIZE; x++)
        {
            bool v = getMap(map, y, x);
            setMap(map, y, x, false);
            setMap(map, y + 1, x, v);
        }
    }
}

void markVisitedState(MAP& map, int y, int x)
{
    visited[y][x].insert(map);
}

bool isVisitedState(MAP& map, int y, int x)
{
    return visited[y][x].find(map) != visited[y][x].end();
}

bool search(MAP map, int y, int x)
{
    // 도착지 가장 오른쪽 윗 칸
    if (y == 0 && x == SIZE - 1)
        return true;

    // 벽이 캐릭터가 있는 칸으로 이동하면 더 이상 캐릭터 이동 불가
    if (getMap(map, y, x))
        return false;

    markVisitedState(map, y, x);

    // cout << y << ',' << x << endl;
    // printMap(map);
    // cout << endl;

    for (int i = 0; i < 9; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!canMove(ny, nx)) // 맵 벗어남
            continue;
        if (getMap(map, ny, nx)) // 벽 있음
            continue;

        MAP nextMap = map;
        moveWalls(nextMap);

        if (!isVisitedState(nextMap, ny, nx))
        {
            if (search(nextMap, ny, nx))
            {
                //cout << ny << "," << nx << endl;
                return true;
            }
        }
    }

    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    MAP map = 0;
    for (int y = 0; y < SIZE; y++)
    {
        string line;
        cin >> line;
        for (int x = 0; x < SIZE; x++)
        {
            if (line[x] == '#')
                setMap(map, y, x, true);
        }
    }

    // 시작점 왼쪽 아래
    cout << search(map, SIZE - 1, 0) ? 1 : 0;
    return 0;
}