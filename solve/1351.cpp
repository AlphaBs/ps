// https://acmicpc.net/problem/1351

#include <iostream>
#include <cstdio>
#include <algorithm>

#define ULL unsigned long long
#define MEM_LIMIT 16'000'000

using namespace std;

ULL mem[MEM_LIMIT];
ULL n, p, q;

ULL solve(ULL i)
{
    if (i == 0)
        return 1;

    if (i < MEM_LIMIT)
    {
        ULL& res = mem[i];
        if (res != 0)
            return res;
        else
            return res = solve(i / p) + solve(i / q);
    }
    else
        return solve(i / p) + solve(i / q);
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