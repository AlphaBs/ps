// https://www.acmicpc.net/problem/2533

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> edges[1'111'111];
bool visited[1'111'111];
int dp[1'111'111][2];

// mark all nodes from the subtree which the root node is `node`
// and return the minimum count
int solve(int node, bool isParentAdapter)
{
    int &res = dp[node][isParentAdapter == 0 ? false : true];
    if (res != -1)
        return res;

    int connectedResult = 0, currentResult = 1;
    for (int connected : edges[node])
    {
        if (!visited[connected])
        {
            visited[connected] = true;
            if (isParentAdapter)
                connectedResult += solve(connected, false);
            currentResult += solve(connected, true);
            visited[connected] = false;
        }
    }
    return res = min(currentResult, isParentAdapter ? connectedResult : 999'999'999);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 1'111'111; i++)
        for (int j = 0; j < 2; j++)
            dp[i][j] = -1;

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    visited[1] = true;
    cout << solve(1, true) << "\n";
    return 0;
}