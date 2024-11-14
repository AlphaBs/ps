// https://www.acmicpc.net/problem/15686

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define pii pair<int, int>

using namespace std;

int n, m, result = INT_MAX;
vector<pii> chicks;
vector<pii> houses;
vector<pii> selected;

bool visit[55][55];
int dist[55][55];

int dy[4] = { 1, -1, 0,  0 };
int dx[4] = { 0,  0, 1, -1 };

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < n))
        return false;
    
    return true;
}

void updateDist()
{
    //for (auto& chick : selected)
    //{
    //    cout << chick.second << ',' << chick.first << ' ';
    //}
    //cout << '\n';

    int totalDist = 0;
    for (auto& house : houses)
    {
        int minChick = INT_MAX;
        for (auto& chick : selected)
        {
            int d = abs(house.first - chick.first) + abs(house.second - chick.second);
            minChick = min(minChick, d);
        }
        totalDist += minChick;
    }
    result = min(result, totalDist);
}

void find(int pos, int count)
{
    if (count == m) 
        return;

    for (int i = pos; i < chicks.size(); i++)
    {
        selected.push_back(chicks[i]);
        updateDist();
        find(i + 1, count + 1);
        selected.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            int v;
            cin >> v;
            if (v == 2)
                chicks.push_back({y, x});
            else if (v == 1)
                houses.push_back({y, x});
        }
    }
    find(0, 0);
    cout << result;
    return 0;
}