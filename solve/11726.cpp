// https://www.acmicpc.net/problem/11726

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MODER = 10007;

int cache[1111];

int solve(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int& ret = cache[n];
    if (ret > 0) return ret;

    ret = (solve(n - 1) + solve(n - 2)) % MODER;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(cache, cache + 1111, -1);

    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}