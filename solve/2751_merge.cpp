#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int nums[1'000'000];
int tmps[1'000'000];

void msort(int left, int right)
{
    if (left == right)
        return;
    
    int mid = (left + right) / 2;
    msort(left, mid);
    msort(mid+1, right);

    int a = left;
    int b = mid + 1;
    int idx = a;
    while (a <= mid && b <= right)
    {
        if (nums[a] < nums[b])
            tmps[idx++] = nums[a++];
        else
            tmps[idx++] = nums[b++];
    }

    while (a <= mid) tmps[idx++] = nums[a++];
    while (b <= right) tmps[idx++] = nums[b++];
    for (int i = left; i <= right; i++) nums[i] = tmps[i];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    msort(0, n - 1);
    for (int i = 0; i < n; i++) cout << nums[i] << "\n";

    return 0;
}