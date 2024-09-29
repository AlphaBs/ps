// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// 가로 M 세로 N
int m, n, k;
bool map[55][55];

bool tryRemoveMap(int y, int x)
{
    if (!(0 <= x && x < m))
        return false;
    if (!(0 <= y && y < n))
        return false;
    if (!map[y][x])
        return false;
    
    map[y][x] = false;
    tryRemoveMap(y - 1, x);
    tryRemoveMap(y + 1, x);
    tryRemoveMap(y, x - 1);
    tryRemoveMap(y, x + 1);
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (--t >= 0)
    {
        cin >> m >> n >> k;
        while (--k >= 0)
        {
            int x, y;
            cin >> x >> y;
            map[y][x] = true;
        }

        int sum = 0;
        for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            if (tryRemoveMap(y, x))
                sum++;
        }
        cout << sum << endl;
    }
    return 0;
}