// https://www.acmicpc.net/problem/1027

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int arr[55];

int find(int i)
{
    int result = 0;
    double a;

    a = -1'000'000'000;
    for (int x = i - 1; x >= 0; x--)
    {
        double d = i - x;
        if (arr[x] > a * d + arr[i])
        {
            result++;
            a = (arr[x] - arr[i]) / d;
        }
    }

    a = -1'000'000'000;
    for (int x = i + 1; x < n; x++)
    {
        double d = x - i;
        if (arr[x] > a * d + arr[i])
        {
            result++;
            a = (arr[x] - arr[i]) / d;
        }
    }

    return result;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxResult = -1;
    for (int i = 0; i < n; i++)
    {
        int r = find(i);
        maxResult = max(maxResult, r);
        //cout << i << ' ' << r << endl;
    }

    cout << maxResult;
    return 0;
}