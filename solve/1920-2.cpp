#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[111'111];
int n;

int lower_bound(int x)
{
    int lo = -1;
    int hi = n;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] >= x)
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        arr[i] = v;
    }

    int v;
    cin >> v;
    cout << arr[lower_bound(v)] << endl;
    return 0;
}