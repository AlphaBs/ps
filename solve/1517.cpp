#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[500'500];
long long result;

void merge(int left, int mid, int right)
{
    static int tmp[500'500];

    int a = left;
    int b = mid + 1;
    int idx = left;

    int count = 0;
    while (a <= mid && b <= right)
    {
        if (arr[a] <= arr[b]) tmp[idx++] = arr[a++], result += count;
        else tmp[idx++] = arr[b++], count += 1;
    }
    while (a <= mid) tmp[idx++] = arr[a++], result += count;
    while (b <= right) tmp[idx++] = arr[b++];
    for (int i = left; i <= right; i++) arr[i] = tmp[i];
}

void solve(int left, int right)
{
    if (left >= right)
        return;
    
    int mid = (left + right) / 2;
    solve(left, mid);
    solve(mid + 1, right);
    return merge(left, mid, right);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    solve(0, n - 1);

    cout << result;
    return 0;
}