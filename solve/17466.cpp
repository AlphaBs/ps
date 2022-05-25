#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, p;
    cin >> n >> p;

    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result = result * i % p;
    }

    cout << result;
    return 0;
}