// https://www.acmicpc.net/problem/15657

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int num[11];
int seq[11];

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
        seq[index] = num[i];
        if (index > 0 && seq[index - 1] > seq[index])
            continue;
        solve(index + 1);
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