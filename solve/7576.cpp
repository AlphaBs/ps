#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

// +1: 익음
//  0: 안익음
// -1: 없음

typedef struct Cord 
{
    int x;
    int y;
} Cord;

int map[1000][1000];

int work(int m, int n, std::queue<Cord>& q)
{
    int effected = 0;
    int length = q.size();
    while (length--)
    {
        Cord c = q.front();
        q.pop();

        int x = c.x;
        int y = c.y;

        // left
        if (x > 0 && map[y][x - 1] == 0)
        {
            map[y][x - 1] = 1;
            effected++;
            q.push((Cord){ x - 1, y });
        }
        // right
        if (x < m - 1 && map[y][x + 1] == 0)
        {
            map[y][x + 1] = 1;
            effected++;
            q.push((Cord){ x + 1, y });
        }
        // up
        if (y > 0 && map[y - 1][x] == 0)
        {
            map[y - 1][x] = 1;
            effected++;
            q.push((Cord){ x, y - 1 });
        }
        // down
        if (y < n - 1 && map[y + 1][x] == 0)
        {
            map[y + 1][x] = 1;
            effected++;
            q.push((Cord){ x, y + 1 });
        }
    }

    return effected;
}

void printMap(int m, int n)
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            std::cout << map[y][x] << " ";
        }

        std::cout << std::endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int m, n, totalZeros = 0;
    std::cin >> m >> n;

    int value;
    std::queue<Cord> q;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < m; x++)
    {
        std::cin >> value;
        map[y][x] = value;
        if (value == 0)
            totalZeros++;
        else if (value == 1)
            q.push((Cord){ x, y });
    }

    int day = 0;
    int totalEffected = 0;
    while (totalEffected < totalZeros) 
    {
        int effected = work(m, n, q);
        //std::cout << effected << std::endl;
        //printMap(m, n);

        totalEffected += effected;
        if (effected == 0)
        {
            if (totalEffected != totalZeros)
                day = -1;
            break;
        }
        day++;
    }

    std::cout << day;
    return 0;
}