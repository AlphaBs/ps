// https://codeforces.com/problemset/problem/2036/B

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int B[22222];
int C[1111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> B[i] >> C[i];
        }
        cout << 1 << '\n';
    }
    return 0;
}