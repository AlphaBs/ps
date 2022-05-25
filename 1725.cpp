#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
long long arr[100'100];

long long findMaxFromMid(int left, int mid, int right)
{
    long long width = 1;
    long long height = arr[mid];
    int l = mid-1;
    int r = mid+1;

    long long result = width * height;
    while (left <= l && r <= right)
    {
        width++;
        if (arr[l] < arr[r]) height = min(height, arr[r++]);
        else height = min(height, arr[l--]);
        result = max(result, width * height);
    }
    while (left <= l) 
    {
        width++;
        height = min(height, arr[l--]);
        result = max(result, width * height);
    }
    while (r <= right)
    {
        width++;
        height = min(height, arr[r++]);
        result = max(result, width * height);
    }

    return result;
}

int solve(int left, int right)
{
    if (left > right) return 0;
    if (left == right) return arr[left];

    int mid = (left + right) / 2;
    int leftResult = solve(left, mid-1);
    int rightResult = solve(mid+1, right);
    int result = findMaxFromMid(left, mid, right);

    return max({leftResult, rightResult, result});
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve(0, n - 1);

    return 0;
}