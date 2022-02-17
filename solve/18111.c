//https://www.acmicpc.net/problem/18111

#include <stdio.h>
#include <stdlib.h>

typedef struct Map {
    int* map;
    int w;
    int h;
} Map;

int getZ(Map* map, int x, int y)
{
    return map->map[(map->w)*y + x];
}

void setZ(Map* map, int x, int y, int z)
{
    map->map[(map->w)*y + x] = z;
}

int check(Map* map, int level, int inventory)
{
    int time = 0;

    for (int y = 0; y < map->h; y++)
    for (int x = 0; x < map->w; x++)
    {
        int z = getZ(map, x, y);

        int changeBlock = z - level;
        if (z > level) // 높으면 부수기
        {
            time += changeBlock * 2; 
            inventory += changeBlock;
        }
        else // 낮으면 블럭설치
        {
            changeBlock *= -1;
            time += changeBlock;
            inventory -= changeBlock;
        }
    }

    if (inventory < 0)
        return -1;
    return time;
}

int main()
{
    int w, h, inven;
    scanf("%d %d %d", &w, &h, &inven);

    Map map;
    map.w = w;
    map.h = h;
    map.map = (int*) malloc(sizeof(int) * w * h);

    int maxZ = -1;
    int minZ = 9999;
    int value;
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
    {
        scanf("%d", &value);
        setZ(&map, x, y, value);

        if (maxZ < value)
            maxZ = value;
        if (minZ > value)
            minZ = value;
    }

    int minTime = 99999999;
    int maxLevel = -1;
    for (int i = maxZ; i >= minZ; i--)
    {
        int time = check(&map, i, inven);
        if (time < 0)
            continue;

        if (minTime > time)
        {
            minTime = time;
            maxLevel = i;
        }
    }

    printf("%d %d", minTime, maxLevel);
    return 0;
}