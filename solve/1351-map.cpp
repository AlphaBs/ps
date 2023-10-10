// https://www.acmicpc.net/problem/1351

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define ULL unsigned long long

using namespace std;

map<ULL, ULL> mem;
ULL n, p, q;

ULL solve(ULL i)
{
    if (mem.find(i) != mem.end())
        return mem[i];

    ULL res;
    if (i == 0)
        res = 1;
    else
        res = solve(i / p) + solve(i / q);
    return mem[i] = res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> p >> q;
    cout << solve(n) << endl;
    
    return 0;
}