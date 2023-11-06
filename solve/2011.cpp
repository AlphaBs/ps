// https://www.acmicpc.net/problem/2011

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int MODER = 1'000'000;
int n;
int arr[5555];
int dp[5555];

bool isValid(int first, int second)
{
    int number = first * 10 + second;
    return 1 <= number && number <= 26;
}

int solve(int index)
{
    if (index == n)
        return 1;
    if (arr[index] == 0)
        return 0;

    int& res = dp[index];
    if (res != -1)
        return res;
    res = 0;

    // one length
    if (index < n && isValid(0, arr[index]))
    {
        res += solve(index + 1);
        res %= MODER;
    }

    // two length
    if (index + 1 < n && isValid(arr[index], arr[index + 1]))
    {
        res += solve(index + 2);
        res %= MODER;
    }

    return res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5555; i++)
        dp[i] = -1;

    string input;
    input.reserve(5555);

    cin >> input;
    n = input.length();
    for (int i = 0; i < n; i++)
        arr[i] = input[i] - '0';

    cout << solve(0) << '\n';
    return 0;
}