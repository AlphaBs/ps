// https://www.acmicpc.net/problem/15654

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int num[11];
int seq[11];
bool used[11];

void solve(int index)
{
    if (index >= m)
    {
        for (int i = 0; i < m; i++)
            cout << seq[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;

        used[i] = true;
        seq[index] = num[i];
        solve(index + 1);
        used[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    solve(0);

    return 0;
}