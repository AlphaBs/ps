// https://www.acmicpc.net/problem/14003

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int input[1'111'111];
vector<int> lis;
vector<int> lisIndex(1'111'111, -1);

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    lis.reserve(1'111'111);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        auto it = lower_bound(lis.begin(), lis.end(), input[i]);
        auto index = distance(lis.begin(), it);
        if (it == lis.end())
        {
            lis.push_back(input[i]);
            lisIndex[i] = lis.size() - 1;
        }
        else
        {
            lis[index] = input[i];
            lisIndex[i] = index;
        }
    }

    cout << lis.size() << '\n';

    vector<int> reversed;
    reversed.reserve(1'111'111);
    
    int index = lis.size() - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (lisIndex[i] == index)
        {
            reversed.push_back(input[i]);
            index--;
        }
    }

    for (int i = reversed.size() - 1; i >= 0; i--)
    {
        cout << reversed[i] << ' ';
    }
    return 0;
}