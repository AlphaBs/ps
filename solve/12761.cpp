// https://www.acmicpc.net/problem/12761

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int a, b, m;
int depth[111'111];

bool canMove(int n)
{
    return 0 <= n && n <= 100'000;
}

int find(int n)
{
    queue<int> q;
    q.push(n);
    depth[n] = 1;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == m)
            return depth[cur];
        
        int nexts[8] = { 
            cur + 1, 
            cur - 1, 
            cur - a, 
            cur + a, 
            cur - b, 
            cur + b, 
            cur * a, 
            cur * b
        };

        for (int i = 0; i < 8; i++)
        {
            if (canMove(nexts[i]) && depth[nexts[i]] == 0)
            {
                depth[nexts[i]] = depth[cur] + 1;
                q.push(nexts[i]);
            }
        }
    }

    return -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> a >> b >> n >> m;
    cout << find(n) - 1;
    return 0;
}