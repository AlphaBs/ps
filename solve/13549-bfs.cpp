// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int n, k;
int dist[111'111];

bool canMove(int n)
{
    return 0 <= n && n <= 100'000;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 111'111; i++)
        dist[i] = 999'999;
    cin >> n >> k;

    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;
    while (!dq.empty())
    {
        int c = dq.front(); dq.pop_front();
        if (c == k) break;

        if (canMove(c * 2) && dist[c * 2] > dist[c])
        {
            dq.push_front(c * 2);
            dist[c * 2] = dist[c];
        }
        if (canMove(c + 1) && dist[c + 1] > dist[c] + 1)
        {
            dq.push_back(c + 1);
            dist[c + 1] = dist[c] + 1;
        }
        if (canMove(c - 1) && dist[c - 1] > dist[c] + 1)
        {
            dq.push_back(c - 1);
            dist[c - 1] = dist[c] + 1;
        }
    }

    cout << dist[k];
    return 0;
}