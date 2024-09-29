// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
pair<int, int> times[111'111];

bool comparer(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        times[i] = make_pair(start, end);
    }

    sort(times, times + n, comparer);

    int count = 0;
    int from = 0;
    for (int i = 0; i < n; i++)
    {
        if (times[i].first >= from)
        {
            from = times[i].second;
            count++;
        }
    }

    cout << count;
    return 0;
}