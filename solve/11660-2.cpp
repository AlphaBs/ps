// https://www.acmicpc.net/problem/11660

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int m;
int smap[1111][1111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int y = 1; y <= n; y++)
    for (int x = 1; x <= n; x++)
    {
        int t;
        cin >> t;
        smap[y][x] = smap[y - 1][x] + smap[y][x - 1] - smap[y - 1][x - 1] + t;
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        int result = smap[y2][x2] - smap[y1 - 1][x2] - smap[y2][x1 - 1] + smap[y1 - 1][x1 - 1];
        cout << result << '\n';
    }

    return 0;
}