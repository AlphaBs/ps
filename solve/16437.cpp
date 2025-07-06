// https://www.acmicpc.net/problem/16437

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

#define ll long long

using namespace std;

int n;
ll wMap[222'222];
ll sMap[222'222];
vector<int> tree[222'222];
bool visit[222'222];

ll move(int from)
{
    assert(!visit[from]);
    visit[from] = true;

    ll totalSheep = sMap[from];
    for (auto& next : tree[from])
    {
        ll movedSheep = move(next);
        totalSheep += max(0LL, movedSheep - wMap[from]);
        wMap[from] = max(0LL, wMap[from] - movedSheep);
    }
    //cout << from << ":" << totalSheep << endl;
    return max(0LL, totalSheep);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        char t;
        ll v;
        int n;
        cin >> t >> v >> n;
        tree[n].push_back(i);
        if (t == 'S')
            sMap[i] = v;
        if (t == 'W')
            wMap[i] = v;
    }
    cout << move(1);
    return 0;
}