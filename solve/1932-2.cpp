#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int map[555][555];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int y = n - 1; y >= 1; y--)
    {
        for (int x = 1; x <= y; x++)
        {
            map[y][x] += max(map[y + 1][x], map[y + 1][x + 1]);
        }
    }

    cout << map[1][1];
    return 0;
}