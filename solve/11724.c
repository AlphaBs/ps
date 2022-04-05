#include <stdio.h>
#include <stdbool.h>

bool map[1001][1001];
bool check[1001];

void dfs(int nodeIndex, int nodeCount)
{
    check[nodeIndex] = true;
    for (int i = 1; i <= nodeCount; i++)
    {
        if (map[nodeIndex][i] && !check[i])
        {
            dfs(i, nodeCount);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][y] = true;
        map[y][x] = true;
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            dfs(i, n);
            count++;
        }
    }

    printf("%d", count);
    return 0;
}