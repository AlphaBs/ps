#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// gcd(a, b) = gcd(|a|, |b|)
// gcd(a, 0) = |a|
// gcd(a, b) = gcd(b, a)
// gcd(a, b) = gcd(a+-b, b)
// gcd(a, b) = gcd(a+nb, b)
// gcd(a, b) = gcd(a mod b, b)
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// ab = gl
int lcm(int a, int b) 
{
    return a / gcd(a, b) * b;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    cin >> a >> b;

    int g = a > b ? gcd(a, b) : gcd(b, a);
    int l = a > b ? lcm(a, b) : lcm(b, a);

    cout << g << "\n" << l;

    return 0;
}