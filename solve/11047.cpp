// https://www.acmicpc.net/problem/11047

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int coin[11];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        coin[i] = v;
    }

    int used = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        used += (k / coin[i]);
        k %= coin[i];
    }

    cout << used;
    return 0;
}