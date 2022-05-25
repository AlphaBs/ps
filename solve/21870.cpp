#include <bits/stdc++.h>

using namespace std;
int arr[200'200];

int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    while (b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

int gcdarr(int from, int to)
{
    if (to - from == 0) return arr[from];

    int result = gcd(arr[from], arr[to]);
    for (int i = from + 1; i <= to; i++)
    {
        result = gcd(result, arr[i]);
    }
    return result;
}

int solve(int left, int right)
{
    if (left == right) return arr[left];

    int mid = (left + right - 1) / 2;

    // 왼쪽 선택
    int leftResult = gcdarr(left, mid) + solve(mid+1, right);
    // 오른쪽 선택
    int rightResult = gcdarr(mid+1, right) + solve(left, mid);

    return max({leftResult, rightResult});
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve(0, n-1);

    return 0;
}