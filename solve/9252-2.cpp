// https://www.acmicpc.net/problem/9252

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

string A;
string B;

int dp[1111][1111];
int result[1111][1111];

int lcs(int a, int b)
{
    if (a >= A.length() || b >= B.length())
        return 0;

    int& ret = dp[a][b];
    if (ret >= 0)
        return ret;

    if (A[a] == B[b])
    {
        int next = lcs(a + 1, b + 1) + 1;
        if (ret < next)
        {
            ret = next;
            result[a][b] = 1;
        }
    }

    int left = lcs(a + 1, b);
    if (ret < left)
    {
        ret = left;
        result[a][b] = 2;
    }
    
    int right = lcs(a, b + 1);
    if (ret < right)
    {
        ret = right;
        result[a][b] = 3;
    }
    return ret;
}

int main() 
{
    for (int i = 0; i < 1111; i++)
    for (int j = 0; j < 1111; j++)
        dp[i][j] = -1;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A;
    cin >> B;

    int a = 0, b = 0;
    int l = lcs(a, b);
    cout << l << '\n';

    while (a < A.length() && b < B.length())
    {
        switch (result[a][b])
        {
            case 1:
                cout << A[a];
                a++, b++;
                break;
            case 2:
                a++;
                break;
            case 3:
                b++;
                break;
        }
    }
    return 0;
}