// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
int map[33][33];
bool visited[33][33];

int dx[4] = { 1, 0, -1,  0 };
int dy[4] = { 0, 1,  0, -1 };

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < n))
        return false;

    return map[y][x] == 1;
}

int countNodes(int y, int x)
{
    int count = 1;

    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (canMove(ny, nx) && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                count++;
                q.push({ny, nx});
            }
        }
    }

    return count;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int y = 0; y < n; y++)
    {
        string line;
        cin >> line;
        for (int x = 0; x < n; x++)
        {
            map[y][x] = line[x] - '0';
        }
    }

    vector<int> counts;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        if (map[y][x] == 1 && !visited[y][x])
        {
            int count = countNodes(y, x);
            counts.push_back(count);
        }
    }

    sort(counts.begin(), counts.end());

    cout << counts.size() << '\n';
    for (const auto& count : counts)
    {
        cout << count << '\n';
    }
    return 0;
}