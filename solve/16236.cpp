// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define pii pair<int, int>

using namespace std;

int n;
int map[22][22];
int dist[22][22];

int sSize = 2;
pii sPos;
int sEaten = 0;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < n))
        return false;
    return true;
}

pii findEatableFish(int d)
{
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        if (dist[y][x] == d && map[y][x] > 0 && map[y][x] < sSize)
        {
            return {y, x};
        }
    }
    return {-1, -1};
}

int find()
{
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
        dist[y][x] = -1;
    
    queue<pii> q;
    q.push({sPos.first, sPos.second});
    dist[sPos.first][sPos.second] = 0;
    
    int mostFarDist = 0;
    while (q.size())
    {
        pii cur = q.front(); q.pop();
        if (map[cur.first][cur.second] <= sSize)
        {
            for (int i = 0; i < 4; i++)
            {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if (canMove(ny, nx) && dist[ny][nx] == -1)
                {
                    q.push({ny, nx});
                    dist[ny][nx] = dist[cur.first][cur.second] + 1;
                    mostFarDist = max(mostFarDist, dist[ny][nx]);
                }
            }
        }
    }

    // 가장 가까운 먹을 수 있는 물고기 찾기
    pii closestEatableFish = {-1, -1};
    for (int d = 1; d <= mostFarDist; d++)
    {
        closestEatableFish = findEatableFish(d);
        if (closestEatableFish.first >= 0) // 발견
            break;
    }

    if (closestEatableFish.first >= 0) // 먹을 수 있는 물고기 발견
    {
        map[closestEatableFish.first][closestEatableFish.second] = 0;
        sEaten++;

        if (sEaten >= sSize)
        {
            sEaten = 0;
            sSize++;
        }

        sPos = closestEatableFish;
        return dist[closestEatableFish.first][closestEatableFish.second];
    }
    else // 먹을 수 있는 물고기 없음
    {
        return -1;
    }
}

void printMap()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (y == sPos.first && x == sPos.second)
                cout << "# ";
            else
                cout << map[y][x] << ' ';
        }
        cout << endl;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            int v;
            cin >> v;
            if (v == 9) {
                sPos = {y, x};
            }
            else {
                map[y][x] = v;
            }
        }
    }

    int t = 0;
    while (true)
    {
        int elapsed = find();
        //printMap();
        //cout << "elapsed " << elapsed << ", size " << sSize << ", eaten " << sEaten << endl;
        if (elapsed == -1)
            break;
        t += elapsed;
    }

    cout << t;
    return 0;
}