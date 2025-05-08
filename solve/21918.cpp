// https://www.acmicpc.net/problem/21918

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool bulbs[5555];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> bulbs[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            bulbs[b] = c;
        }
        else if (a == 2)
        {
            for (int j = b; j <= c; j++)
            {
                bulbs[j] = !bulbs[j];
            }
        }
        else if (a == 3)
        {
            for (int j = b; j <= c; j++)
            {
                bulbs[j] = false;
            }
        }
        else if (a == 4)
        {
            for (int j = b; j <= c; j++)
            {
                bulbs[j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (bulbs[i] ? '1' : '0') << ' ';
    }

    return 0;
}