// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, w;
int cost[1111];
vector<int> dep[1111];
bool built[1111];
int dp[1111];

int build(int node)
{
    int& ret = dp[node];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int item : dep[node])
    {
        ret = max(ret, build(item));
    }
    ret += cost[node];
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
        for (int i = 0; i < 1111; i++)
        {
            dep[i].clear();
            built[i] = false;
            dp[i] = -1;
        }

        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> cost[i];
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            dep[y].push_back(x);
        }
        cin >> w;

        cout << build(w) << '\n';
    }

    return 0;
}