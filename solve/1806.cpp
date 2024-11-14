// https://www.acmicpc.net/problem/1806

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define INT_MAX 123'456'789

using namespace std;

int n, s;
int arr[111'111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0, right = 0;
    int partSum = arr[0];
    int minLength = INT_MAX;
    while (true)
    {
        if (s <= partSum)
        {
            minLength = min(minLength, right - left + 1);
            partSum -= arr[left];
            left++;
        }
        else
        {
            right++;
            partSum += arr[right];
            if (right > n) 
                break;
        }
    }

    if (minLength == INT_MAX)
        cout << 0;
    else
        cout << minLength;
    return 0;
}