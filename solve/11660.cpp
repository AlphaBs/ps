// https://www.acmicpc.net/problem/11660

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int summap[1111][1111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            int v;
            cin >> v;
            summap[y][x] = summap[y][x - 1] + summap[y - 1][x] - summap[y - 1][x - 1] + v;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int result = summap[y2][x2] - summap[y1 - 1][x2] - summap[y2][x1 - 1] + summap[y1 - 1][x1 - 1];
        cout << result << '\n';
    }

    return 0;
}