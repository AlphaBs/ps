// acmicpc 13397

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int arr[5555];

// 각 구간의 점수가 maxScore 를 넘으면 않게 구간을 나누고, 
// 이때 구간이 몇개 생기는지 계산
int calRanges(int maxScore)
{
    int ranges = 1;
    int minv = 11111, maxv = 0;
    for (int i = 0; i < n; i++)
    {
        minv = min(minv, arr[i]);
        maxv = max(maxv, arr[i]);
        if (maxv - minv > maxScore)
        {
            ranges++;
            minv = arr[i];
            maxv = arr[i];
        }
    }
    return ranges;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int left = 0, right = 0, mid;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        right = max(right, arr[i]);
    }
    
    int result = right; // max
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (calRanges(mid) <= m)
        {
            result = min(result, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << result;
    return 0;
}