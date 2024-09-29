// https://www.acmicpc.net/problem/11659

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
long long sum[111'111];

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
        sum[i + 1] = sum[i] + v;
    }

    for (int a = 0; a < m; a++)
    {
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << '\n';
    }
    return 0;
}