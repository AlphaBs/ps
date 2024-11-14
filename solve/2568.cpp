// https://www.acmicpc.net/problem/2568

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>
#define pii pair<int, int>

using namespace std;

int n;
pii input[111'111];
vector<int> B;
vector<int> lis;
int lisIndex[111'111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lis.reserve(111'111);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        input[i] = {a, b};
    }
    sort(input, input + n);

    for (int i = 0; i < n; i++)
    {
        B.push_back(input[i].second);
    }

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), B[i]);
        auto index = distance(lis.begin(), it);
        if (it == lis.end())
        {
            lis.push_back(B[i]);
            lisIndex[i] = lis.size() - 1;
        }
        else
        {
            lis[index] = B[i];
            lisIndex[i] = index;
        }
    }

    cout << (n - lis.size()) << '\n';

    unordered_set<int> result;
    int index = lis.size() - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (index == lisIndex[i])
        {
            result.insert(B[i]);
            index--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!result.count(input[i].second))
            cout << input[i].first << '\n';
    }

    return 0;
}