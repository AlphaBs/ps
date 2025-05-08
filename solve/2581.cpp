// https://www.acmicpc.net/problem/2581

#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_PRIME 10'000

using namespace std;

bool map[11111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map[1] = false;
    for (int i = 2; i <= MAX_PRIME; i++)
    {
        map[i] = true;
    }

    for (int i = 2; i <= MAX_PRIME; i++)
    {
        if (!map[i])
            continue;

        for (int j = 2;;j++)
        {
            int num = i * j;
            if (num > MAX_PRIME)
                break;

            map[num] = false;
        }
    }

    int m, n;
    cin >> m >> n;

    int sum = 0;
    int minPrime = 999'999'999;
    for (int i = m; i <= n; i++)
    {
        if (map[i])
        {
            minPrime = min(minPrime, i);
            sum += i;
        }
    }

    if (sum == 0)
    {
        cout << "-1";
    }
    else
    {
        cout << sum << '\n' << minPrime;
    }

    return 0;
}