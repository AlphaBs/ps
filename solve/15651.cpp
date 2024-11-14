// https://www.acmicpc.net/problem/15651

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int result[10];

void perm(int count)
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

    for (int i = 1; i <= n; i++)
    {
        result[count] = i;
        perm(count + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    perm(1);
    return 0;
}