// https://www.acmicpc.net/problem/1916

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int n, m, start, dest;
vector<pair<int, int>> costs[1111];
priority_queue<pair<int, int>> pq;
int results[1111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, d, c;
        cin >> s >> d >> c;
        costs[s].push_back({d, c});
    }
    cin >> start >> dest;

    // initialize
    pq.push({start, 0});
    results[start] = 0;
    for (int i = 0; i < 1111; i++) 
        results[i] = 999'999'999;

    // dijkstra
    while (!pq.empty())
    {
        int currentCity = pq.top().first;
        int totalCostToCurrentCity = pq.top().second;
        pq.pop();

        if (totalCostToCurrentCity > results[currentCity])
            continue;

        for (int i = 0; i < costs[currentCity].size(); i++)
        {
            int connectedCity = costs[currentCity][i].first;
            int costToConnectedCity = costs[currentCity][i].second;
            int totalCostToConnectedCity = totalCostToCurrentCity + costToConnectedCity;

            if (totalCostToConnectedCity < results[connectedCity])
            {
                results[connectedCity] = totalCostToConnectedCity;
                pq.push({connectedCity, totalCostToConnectedCity});
            }
        }
    }

    cout << results[dest] << endl;
    return 0;
}