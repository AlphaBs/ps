// https://www.acmicpc.net/problem/1932

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int map[555][555]; // 1-based level, 0-based siblings

// the count of siblings in the specified level is same as the value of the level.
void maximizeMap(int level)
{
    if (level == n)
        return;

    maximizeMap(level + 1);
    for (int i = 0; i < level; i++)
    {
        int largest = max(
            map[level + 1][i],    // left
            map[level + 1][i + 1]); // right

        map[level][i] += largest;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> map[i][j];
        }
    }

    maximizeMap(1);
    cout << map[1][0];

    return 0;
}