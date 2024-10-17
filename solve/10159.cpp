// https://www.acmicpc.net/problem/10159

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
bool map[111][111];
bool result[111][111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = true;
    }

    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        map[i][j] = map[i][j] || (map[i][k] && map[k][j]);
    
    for (int i = 1; i <= n; i++)
    {
        int r = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!map[i][j] && !map[j][i])
                r++;
        }
        cout << r - 1 << '\n';
    }
    return 0;
}
