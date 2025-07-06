// https://www.acmicpc.net/problem/3673

#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll unsigned long long

using namespace std;

ll arr[55555];
ll counts[1'111'111];

ll comb2(ll n)
{
    return n * (n - 1) / 2;
}

ll solve(int n, ll d)
{
    //counts[0] = 1;
    for (int i = 0; i < 1'111'111; i++)
    {
        counts[i] = 0;
    }

    ll currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum = (currentSum + arr[i]) % d;
        counts[currentSum]++;
    }

    ll count = 0;
    for (int i = 0; i < d; i++)
    {
        // counts[i] 개 중에서 2개 뽑는 경우의 수
        if (counts[i] >= 2)
            count += comb2(counts[i]);
    }
    return count;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int tc;
    cin >> tc;
    for (int tt = 0; tt < tc; tt++)
    {
        ll d, n;
        cin >> d >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << solve(n, d) << '\n';
    }

    return 0;
}