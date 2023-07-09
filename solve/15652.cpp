// https://www.acmicpc.net/problem/15652

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int arr[11];

void solve(int index, int start)
{
    // reach end
    if (index >= m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i <= n; i++)
    {
        arr[index] = i;
        solve(index + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    solve(0, 1);
    
    return 0;
}