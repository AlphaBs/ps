// https://www.acmicpc.net/problem/9252

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

string arr1;
string arr2;
int dp[1111][1111];
int lcs[1111][1111];

int solve(int idx1, int idx2)
{
    if (idx1 == arr1.length() || idx2 == arr2.length())
        return 0;

    int& lcsLength = dp[idx1][idx2];
    if (lcsLength != -1)
        return lcsLength;
    int& lcsNumber = lcs[idx1][idx2];

    int next1 = solve(idx1 + 1, idx2);
    int next2 = solve(idx1, idx2 + 1);

    if (next1 > next2)
    {
        lcsLength = next1;
        lcsNumber = 1;
    }
    else // next1 < next2
    {
        lcsLength = next2;
        lcsNumber = 2;
    }

    if (arr1[idx1] == arr2[idx2])
    {
        int next3 = solve(idx1 + 1, idx2 + 1) + 1;
        if (lcsLength < next3)
        {
            lcsLength = next3;
            lcsNumber = 3;
        }
    }
    return lcsLength;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 1111; i++)
    for (int j = 0; j < 1111; j++)
    {
        dp[i][j] = -1;
        lcs[i][j] = -1;
    }

    cin >> arr1 >> arr2;
    cout << solve(0, 0) << '\n';

    int a = 0, b = 0;
    while (lcs[a][b] != -1)
    {
        switch (lcs[a][b])
        {
            case 1:
                a += 1;
                break;
            case 2:
                b += 1;
                break;
            case 3:
                cout << arr1[a];
                a += 1;
                b += 1;
                break;
        }
    }
    return 0;
}