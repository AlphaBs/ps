// https://www.acmicpc.net/problem/15663

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int result[10];
int used[11111];

void solve(int count)
{
    if (count > m)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (used[i] > 0)
        {
            used[i]--;
            result[count] = i;
            solve(count + 1);
            used[i]++;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        used[v]++;
    }
    solve(1);
    return 0;
}