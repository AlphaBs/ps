// https://www.acmicpc.net/problem/1111

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define CHECK_ERROR 999'999

int n;
int arr[55];

int check(int a, int b)
{
    int expectedNext = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (expectedNext == arr[i])
        {
            expectedNext = arr[i] * a + b;
        }
        else
        {
            return CHECK_ERROR;
        }
    }
    return expectedNext;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << 'A';
    }
    else if (n == 2)
    {
        if (arr[0] == arr[1])
        {
            cout << arr[1];
        }
        else
        {
            cout << 'A';
        }
    }
    else
    {
        if (arr[0] == arr[1])
        {
            if (check(1, 0) != CHECK_ERROR)
                cout << arr[1];
            else
                cout << 'B';
        }
        else
        {
            int a = (arr[1] - arr[2]) / (arr[0] - arr[1]);
            int b = arr[1] - arr[0] * a;
            int result = check(a, b);
            if (result == CHECK_ERROR)
                cout << 'B';
            else
                cout << result;
        }
    }
}