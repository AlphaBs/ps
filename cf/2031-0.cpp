// https://codeforces.com/contest/2031/problem/0
 
#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int n;
int H[55];
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        cin >> n;
        for (int i = 0; i < 55; i++)
            H[i] = 0;
        
        for (int i = 0; i < n; i++)
        {
            int v;
            cin >> v;
            H[v]++;
        }

        int maxV = 1;
        int maxCount = 1;
        for (int i = 1; i <= n; i++)
        {
            if (maxCount < H[i])
            {
                maxCount = H[i];
                maxV = i;
            }
        }

        cout << n - maxCount << '\n';
    }
 
    return 0;
}