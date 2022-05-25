#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int nums[5'000'001];

void sieve(int n) {
    for (int i = 2; i <= n; i++)
    {
        if (nums[i] > 0) continue;
        nums[i] = i;
        for (int j = i+i; j <= n; j += i)
            if (nums[j] == 0)
                nums[j] = i;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    sieve(5'000'000);

    while (n--)
    {
        int k; cin >> k;
        while (k > 1) {
            cout << nums[k] << " ";
            k /= nums[k];
        }
        cout << "\n";
    }

    return 0;
}