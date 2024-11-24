// https://codeforces.com/contest/2031/problem/D
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
 
using namespace std;
 
int n;
int tree[555555];
int dp[555555];
 
int find(int start)
{
    int& ret = dp[start];
    if (ret != -1)
        return ret;
 
    ret = tree[start];
    for (int i = 0; i < n; i++)
    {
        if (i < start && tree[i] > tree[start])
        {
            ret = max(ret, find(i));
        }
        else if (start < i && tree[start] > tree[i])
        {
            ret = max(ret, find(i));
        }
    }
    return ret;
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        fill(&dp[0], &dp[0] + sizeof(dp) / sizeof(int), -1);
 
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tree[i];
        }
        for (int i = 0; i < n; i++)
            cout << find(i) << ' ';
        cout << '\n';
    }
    
    return 0;
}