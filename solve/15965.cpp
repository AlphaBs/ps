#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAX_PRIME 8'000'000

using namespace std;

// pi(8,000,000) = 539,777
bool prime[MAX_PRIME];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 1 <= k <= 500,000
    int k;
    cin >> k;

    int until = sqrt(MAX_PRIME);
    int count = 1; // 2 소수 포함
    for (int i = 3; i < MAX_PRIME; i += 2) // 3 부터 홀수만 확인
    {
        if (!prime[i])
        {
            count++;
            if (count == k) {
                cout << i;
                return 0;
            }

            // 2i, 3i, 4i, ... , (i-1)i 는 앞에서 지워졌기 때문에
            // i*i 부터 시작해도 된다
            prime[i] = true;
            if (i <= until)
                for (int j = i*i; j < MAX_PRIME; j += i)
                    prime[j] = true;
        }
    }

    return 0;
}