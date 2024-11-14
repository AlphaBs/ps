// https://www.acmicpc.net/problem/10942

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int arr[2222];
int dp[2222][2222];

int find(int s, int e)
{
    if (s == e) 
        return 1;
    if (s + 1 == e) 
        return (arr[s] == arr[e]) ? 1 : 0;
    
    int& ret = dp[s][e];
    if (ret != -1)
        return ret;

    return ret = (find(s + 1, e - 1) && arr[s] == arr[e]) ? 1 : 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 2222; i++)
    for (int j = 0; j < 2222; j++)
        dp[i][j] = -1;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << find(s, e) << '\n';
    }
    return 0;
}