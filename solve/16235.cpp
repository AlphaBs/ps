// https://www.acmicpc.net/problem/16235

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>

using namespace std;

struct Tree
{
    int y, x, age;
};

int n, m, k;
int addEnergy[11][11];
int currentEnergy[11][11];
int deadEnergy[11][11];
priority_queue<int, vector<int>, greater<int>> tree[11][11];

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool canMove(int y, int x)
{
    if (!(1 <= y && y <= n))
        return false;
    if (!(1 <= x && x <= n))
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            cin >> addEnergy[y][x];
            currentEnergy[y][x] = 5;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int r, c, z;
        cin >> r >> c >> z;
        tree[r][c].push(z);
    }

    for (int year = 1; year <= k; year++)
    {
        vector<Tree> autumnTrees;

        // spring
        for (int y = 1; y <= n; y++)
        {
            for (int x = 1; x <= n; x++)
            {
                deadEnergy[y][x] = 0;

                while (tree[y][x].size())
                {
                    int currentTree = tree[y][x].top();
                    tree[y][x].pop();

                    if (currentEnergy[y][x] - currentTree >= 0) // grow
                    {
                        currentEnergy[y][x] -= currentTree;
                        currentTree++;
                        autumnTrees.push_back({y, x, currentTree});
                    }
                    else // dead
                    {
                        deadEnergy[y][x] += (currentTree / 2);
                    }
                }
            }
        }

        // summer
        for (int y = 1; y <= n; y++)
        {
            for (int x = 1; x <= n; x++)
            {
                currentEnergy[y][x] += deadEnergy[y][x];
            }
        }

        // autumn
        for (int i = 0; i < autumnTrees.size(); i++)
        {
            Tree t = autumnTrees[i];
            tree[t.y][t.x].push(t.age);

            if (t.age % 5 == 0)
            {
                for (int i = 0; i < 8; i++)
                {
                    int ny = t.y + dy[i];
                    int nx = t.x + dx[i];
                    if (canMove(ny, nx))
                        tree[ny][nx].push(1);
                }
            }
        }

        // winter
        for (int y = 1; y <= n; y++)
        {
            for (int x = 1; x <= n; x++)
            {
                currentEnergy[y][x] += addEnergy[y][x];
            }
        }
    }

    int aliveTrees = 0;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            aliveTrees += tree[y][x].size();
        }
    }
    cout << aliveTrees;
    return 0;
}