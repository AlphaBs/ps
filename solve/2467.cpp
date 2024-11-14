// https://www.acmicpc.net/problem/2467

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int arr[111'111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int minDist = 2'000'000'000;
    int mLeft = 0, mRight = n - 1;
    int left = 0, right = n - 1;
    while (left < right)
    {
        int d = arr[left] + arr[right];
        if (abs(d) < minDist)
        {
            mLeft = left; 
            mRight = right;
            minDist = abs(d);
        }

        if (d == 0)
            break;
        if (d > 0)
            right--;
        if (d < 0)
            left++;
    }
    cout << arr[mLeft] << ' ' << arr[mRight];
    return 0;
}