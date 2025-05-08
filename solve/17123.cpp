#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int row[1111];
int col[1111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        // init
        for (int i = 0; i < 1111; i++)
        {
            row[i] = 0;
            col[i] = 0;
        }

        // input
        int n, m;
        cin >> n >> m;
        for (int y = 1; y <= n; y++)
        for (int x = 1; x <= n; x++)
        {
            int input;
            cin >> input;
            row[y] += input;
            col[x] += input;
        }
        
        // v
        for (int i = 0; i < m; i++)
        {
            int r1, c1, r2, c2, v;
            cin >> r1 >> c1 >> r2 >> c2 >> v;

            for (int y = r1; y <= r2; y++)
            for (int x = c1; x <= c2; x++)
            {
                row[y] += v;
                col[x] += v;
            }
        }

        // output row
        for (int i = 1; i <= n; i++)
        {
            cout << row[i] << ' ';
        }
        cout << '\n';

        // output col
        for (int i = 1; i <= n; i++)
        {
            cout << col[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}