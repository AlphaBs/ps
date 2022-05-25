#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long func(long long a, long long b, long long c)
{
    if (b == 0)
        return 1 % c;

    long long half = func(a, b / 2, c);
    if (b % 2 == 0)
        return half * half % c;
    else
        return (((half * half) % c) * a) % c;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << func(a % c, b, c);

    return 0;
}
