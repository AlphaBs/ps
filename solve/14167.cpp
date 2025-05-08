// https://www.acmicpc.net/problem/14167

#include <iostream>
#include <cstdio>
#include <algorithm>

#define pii pair<int, int>
#define ll long long

using namespace std;

int n;
pii cows[1111];
ll distances[1111][1111];
bool visit[1111];

ll calcDist(int a, int b)
{
    ll d1 = abs(cows[a].first - cows[b].first);
    ll d2 = abs(cows[a].second - cows[b].second);
    return d1 * d1 + d2 * d2;
}

void dfs(int cow, int d)
{
    for (int i = 0; i < n; i++)
    {
        if (!visit[i] && distances[cow][i] <= d)
        {
            visit[i] = true;
            dfs(i, d);
        }
    }
}

bool check(int d)
{
    for (int i = 0; i < n; i++)
        visit[i] = false;
    
    visit[0] = true;
    dfs(0, d);

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
            return false;
    }

    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        cows[i].first = y;
        cows[i].second = x;
    }

    int maxDist = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int d = calcDist(i, j);
            distances[i][j] = distances[j][i] = d;
            maxDist = max(maxDist, d);
        }
    }

    int lo = 0;
    int hi = maxDist;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (check(lo) == check(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    cout << hi;
    return 0;
}