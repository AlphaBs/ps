// https://www.acmicpc.net/problem/12738

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> lis;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lis.reserve(1'111'111);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;

        auto it = lower_bound(lis.begin(), lis.end(), next);
        if (it == lis.end())
        {
            lis.push_back(next);
        }
        else
        {
            *it = next;
        }
    }

    cout << lis.size();
    return 0;
}