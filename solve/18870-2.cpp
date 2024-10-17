// https://www.acmicpc.net/problem/18870

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    vector<int> tempList(list);
    sort(tempList.begin(), tempList.end());
    tempList.erase(unique(tempList.begin(), tempList.end()), tempList.end());

    for (int i = 0; i < n; i++)
    {
        auto pos = lower_bound(tempList.begin(), tempList.end(), list[i]);
        cout << pos - tempList.begin() << ' ';
    }
    return 0;
}