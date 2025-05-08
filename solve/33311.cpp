// https://www.acmicpc.net/problem/33311

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        vector<ll> leftSide;
        vector<ll> rightSide;

        int n, l, r;
        cin >> n >> l >> r;
        for (int i = 0; i < n; i++)
        {
            ll v;
            cin >> v;

            if (i <= r - 1)
                leftSide.push_back(v);
            if (i >= l - 1)
                rightSide.push_back(v);
        }

        sort(leftSide.begin(), leftSide.end());
        sort(rightSide.begin(), rightSide.end());

        ll leftSum = 0;
        ll rightSum = 0;
        for (int i = 0; i < (r - l + 1); i++)
        {
            leftSum += leftSide[i];
            rightSum += rightSide[i];
        }

        cout << min(leftSum, rightSum) << '\n';
    }
    return 0;
}