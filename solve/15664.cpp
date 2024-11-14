// https://www.acmicpc.net/problem/15664

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int input[11111];
int result[11];

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
        if (input[i] > 0 && result[count - 1] <= i)
        {
            input[i]--;
            result[count] = i;
            solve(count + 1);
            input[i]++;
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
        input[v]++;
    }
    solve(1);
    return 0;
}