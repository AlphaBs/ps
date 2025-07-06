// https://www.acmicpc.net/problem/9358

#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        ll n;
        ll arr[111];
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        while (n > 2)
        {
            for (int i = 0; i < (n / 2); i++)
            {
                arr[i] += arr[n - i - 1];
            }

            if (n % 2 == 0) // 짝수
            {
                n = n / 2;
            }
            else // 홀수
            {
                arr[n / 2] *= 2;
                n = n / 2 + 1;
            }
        }

        cout << "Case #" << tt << ": ";
        if (arr[0] > arr[1])
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }

    return 0;
}