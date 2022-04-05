#include <iostream>

bool map[128][128];

typedef struct MapInfo 
{
    int whites;
    int blacks;
} MapInfo;

bool checkMap(MapInfo& mapInfo, int startX, int startY, int endX, int endY)
{
    bool start = map[startY][startX];
    for (int y = startY; y <= endY; y++)
    for (int x = startX; x <= endX; x++)
    {
        if (start != map[y][x])
            return false;
    }

    if (start)
        mapInfo.blacks++;
    else
        mapInfo.whites++;

    return true;
}

void cut(MapInfo& map, int n, int startX, int startY, int endX, int endY)
{
    if (checkMap(map, startX, startY, endX, endY))
        return;

    n /= 2;
    cut(map, n, startX, startY, startX + n - 1, startY + n - 1); // part 1
    cut(map, n, startX + n, startY, endX, startY + n - 1); // part 2
    cut(map, n, startX, startY + n, startX + n - 1, endY); // part 3
    cut(map, n, startX + n, startY + n, endX, endY); // part 4
}

int main()
{
    int n;
    std::cin >> n;

    int input;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        std::cin >> input;
        map[y][x] = (input == 1);
    }

    MapInfo mapInfo;
    mapInfo.whites = 0;
    mapInfo.blacks = 0;

    //checkMap(mapInfo, 0,0,1,1);
    cut(mapInfo, n, 0, 0, n-1, n-1);
    std::cout << mapInfo.whites << std::endl << mapInfo.blacks << std::endl;

    return 0;
}