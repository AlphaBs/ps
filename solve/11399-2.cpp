// https://www.acmicpc.net/problem/11399

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int p[1111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        p[i] = v;
    }

    sort(p, p + n);

    for (int i = 1; i < n; i++)
    {
        p[i] = p[i] + p[i - 1];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += p[i];
    cout << sum;
    return 0;
}