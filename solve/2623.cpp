// https://www.acmicpc.net/problem/2623

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> dep[1111];
bool visit[1111];
bool used[1111];
bool cycle = false;
vector<int> order;

void solve(int node)
{
    if (used[node])
    {
        cycle = true;
        return; 
    }

    if (visit[node])
        return;
    
    visit[node] = true;
    used[node] = true;
    
    for (auto& item : dep[node])
    {
        solve(item);
    }

    order.push_back(node);
    used[node] = false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;

        int previous, current;
        for (int j = 0; j < c; j++)
        {
            cin >> current;
            if (j != 0)
            {
                dep[current].push_back(previous);
            }
            previous = current;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }

    if (cycle)
        cout << "0";
    else
    {
        for (auto& item : order)
        {
            cout << item << '\n';
        }
    }
    return 0;
}