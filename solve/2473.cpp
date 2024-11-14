// https://www.acmicpc.net/problem/2473

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#define ll long long

using namespace std;

int n;
ll arr[5555];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int m1, m2, m3;
    ll minValue = LONG_LONG_MAX;
    for (int i = 0; i <= n - 3; i++)
    {
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            ll s = arr[i] + arr[left] + arr[right];
            if (abs(s) < minValue)
            {
                minValue = abs(s);
                m1 = i; m2 = left; m3 = right;
            }

            if (s == 0)
            {
                break;
            }
            if (s < 0)
            {
                left++;
            }
            if (s > 0)
            {
                right--;
            }
        }
    }

    cout << arr[m1] << ' ' << arr[m2] << ' ' << arr[m3];
    return 0;
}