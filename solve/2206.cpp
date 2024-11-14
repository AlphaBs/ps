// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct State
{
    int y;
    int x;
    bool breakable;
    int dist;
};

// y-n x-m
int n, m;
bool map[1111][1111];
bool visit[1111][1111][2]; // 0: 부수지 않음, 1: 부숨

int dy[] = { 1, -1, 0,  0 };
int dx[] = { 0,  0, 1, -1 };

int find()
{
    queue<State> q;
    q.push({1, 1, true, 1});
    visit[1][1][0] = true;
    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        bool breakable = q.front().breakable;
        int dist = q.front().dist;
        q.pop();

        if (y == n && x == m)
            return dist;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (!(1 <= ny && ny <= n)) continue;
            if (!(1 <= nx && nx <= m)) continue;
            
            if (breakable) // 부술수있다
            {
                if (!map[ny][nx] && !visit[ny][nx][0]) // 그냥가기
                {
                    visit[ny][nx][0] = true;
                    q.push({ny, nx, true, dist + 1});
                }
                if (map[ny][nx]) // 부수기
                {
                    visit[ny][nx][1] = true;
                    q.push({ny, nx, false, dist + 1});
                }
            }
            else // 이미 부숨
            {
                if (!map[ny][nx] && !visit[ny][nx][1]) // 벽 없는곳만 이동가능
                {
                    visit[ny][nx][1] = true;
                    q.push({ny, nx, false, dist + 1});
                }
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
    
    cin >> n >> m;
    for (int y = 1; y <= n; y++)
    {
        string line;
        cin >> line;
        for (int x = 0; x < m; x++)
        {
            map[y][x + 1] = (line[x] == '0' ? false : true);
        }
    }

    cout << find();
    return 0;
}