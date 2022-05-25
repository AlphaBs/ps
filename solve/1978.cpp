#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool isPrime(int n) 
{
    if (n <= 1)
        return false;

    for (int i = 2; i*i <= n; i++) 
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// 시간복잡도 안커서 그냥 다 돌려봐도 됨
// 100 * root(1000) ~= 30,000
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // n <= 100
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // value <= 1000
        int value;
        cin >> value;
        if (isPrime(value)) {
            count++;
        }
    }

    cout << count;
    return 0;
}