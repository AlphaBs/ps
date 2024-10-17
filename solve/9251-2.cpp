// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

string arr1;
string arr2;

int dp[1111][1111];

int solve(int index1, int index2)
{
    if (index1 >= arr1.length() || index2 >= arr2.length())
        return 0;

    int& ret = dp[index1][index2];
    if (ret >= 0) return ret;

    if (arr1[index1] == arr2[index2])
    {
        ret = solve(index1 + 1, index2 + 1) + 1;
    }
    else
    {
        ret = max(solve(index1 + 1, index2), solve(index1, index2 + 1));
    }
    return ret;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 1111; i++)
    for (int j = 0; j < 1111; j++)
        dp[i][j] = -1;

    cin >> arr1 >> arr2;
    cout << solve(0, 0);

    return 0;
}