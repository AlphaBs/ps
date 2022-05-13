#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int nums[20];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int count = 0;
    for (int i = 1; i < (1<<n); i++)
    {
        int bits = i;
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (bits & 1)
                sum += nums[j];
            bits = bits >> 1;
        }
        if (sum == s)
            count++;
    }
    
    cout << count;
    return 0;
}