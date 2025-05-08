// https://www.acmicpc.net/problem/17266

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int lights[111'111];

bool check(int h)
{
    int start = 0;

    for (int i = 0; i < m; i++)
    {
        if (lights[i] - h > start)
            return false;
        start = lights[i] + h;
    }

    return start >= n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> lights[i];
    }

    int left = 1;
    int right = n + 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left;
    return 0;
}