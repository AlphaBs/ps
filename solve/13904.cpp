// https://www.acmicpc.net/problem/13904

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define pii pair<int, int>

using namespace std;

int n;
pii works[1111];
int dp[1111][1111];

// 1000 * 1000 = 1'000'000
int findMaxScore(int index, int pastDays)
{
    if (index >= n) return 0;
    int& ret = dp[index][pastDays];
    if (ret >= 0)
        return ret;
    pii current = works[index];
    ret = max(ret, findMaxScore(index + 1, pastDays));
    if (pastDays < current.first)
        ret = max(ret, findMaxScore(index + 1, pastDays + 1) + current.second);
    return ret;
}

int main() 
{
    for (int i = 0; i < 1111; i++)
    for (int j = 0; j < 1111; j++)
        dp[i][j] = -1;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d, w;
        cin >> d >> w;
        works[i] = {d, w};
    }

    sort(works, works + n, [](const pii& a, const pii& b) 
    {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    });

    // for (int i = 0; i < n; i++)
    // {
    //     cout << works[i].first << ' ' << works[i].second << '\n';
    // }

    cout << findMaxScore(0, 0);
    return 0;
}