// https://www.acmicpc.net/problem/11727

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MODER = 10007;
int cache[1111];

int solve(int n)
{
    int& ret = cache[n];
    if (n == 0 || ret > 0)
        return ret;
    
    ret = (solve(n - 1) + solve(n - 2) * 2) % MODER;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 3;
    cache[3] = 5;

    int n;
    cin >> n;
    cout << solve(n) % MODER;

    return 0;
}