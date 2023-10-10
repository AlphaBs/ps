// https://www.acmicpc.net/problem/1354

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

#define LL long long

using namespace std;

unordered_map<LL, LL> mem;
LL n, p, q, x, y;

LL solve(LL i)
{
    if (i <= 0)
        return 1;
    
    if (mem.find(i) != mem.end())
        return mem[i];
    
    return mem[i] = solve(i / p - x) + solve(i / q - y);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> p >> q >> x >> y;
    cout << solve(n) << endl;

    return 0;
}