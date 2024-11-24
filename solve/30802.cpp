// https://www.acmicpc.net/problem/30802

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1'000'000'000
    int n;
    cin >> n;
    int arr[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    int t, p;
    cin >> t >> p;

    int tResult = 0;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] != 0)
            tResult += (arr[i] - 1) / t + 1;
    }
    cout << tResult << '\n';
    cout << (n / p) << ' ' << (n % p);
    return 0;
}