// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int d[1111];
vector<int> prerequisites[1111];
int dp[1111];

int solve(int w) 
{
    int& res = dp[w];
    if (res != -1)
        return res;
    
    int pre = 0;
    for (int i = 0; i < prerequisites[w].size(); i++)
    {
        pre = max(pre, solve(prerequisites[w][i]));
    }
    return res = pre + d[w];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 1111; i++)
        {
            dp[i] = -1;
            prerequisites[i].clear();
        }

        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> d[i];
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            prerequisites[y].push_back(x);
        }

        int w;
        cin >> w;
        cout << solve(w) << "\n";
    }

    return 0;
}