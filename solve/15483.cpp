// https://www.acmicpc.net/problem/15483

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    cin >> A >> B;
    int dp[2][1111];

    for (int a = A.length(); a >= 0; a--)
    {
        for (int b = B.length(); b >= 0; b--)
        {
            if (a == A.length())
            {
                dp[a % 2][b] = (int)B.length() - b;
            }
            else if (b == B.length())
            {
                dp[a % 2][b] = (int)A.length() - a;
            }
            else
            {
                int insertCost = dp[a % 2][b + 1] + 1;
                int deleteCost = dp[(a + 1) % 2][b] + 1;
                int replaceCost = dp[(a + 1) % 2][b + 1];
                if (A[a] != B[b])
                    replaceCost++;
                dp[a % 2][b] = min({replaceCost, insertCost, deleteCost});
            }
        }
    }

    cout << dp[0][0];
    return 0;
}