// https://www.acmicpc.net/problem/6549

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

#define ll long long
#define pii pair<ll, ll>

using namespace std;

ll n;
ll h[111'111];

ll find()
{
    ll maxSize = 0;
    stack<pii> states;
    for (int i = 0; i < n; i++)
    {
        int startIndex = i;

        while (states.size())
        {
            pii top = states.top();
            if (top.first >= h[i])
            {
                states.pop();
                maxSize = max(maxSize, top.first * (i - top.second));
                startIndex = top.second;
            }
            else
                break;
        }

        states.push({h[i], startIndex});
    }

    while (states.size())
    {
        pii top = states.top();
        states.pop();
        maxSize = max(maxSize, top.first * (n - top.second));
    }

    return maxSize;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            cin >> h[i];

        cout << find() << '\n';
    }

    return 0;
}