// DP

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int coins[111]; // 1-based index
int D[100'100];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 1<=n<=100
    // 1<=k<=10,000
    // 1<=nk<=1,000,000
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> coins[i];

    // A1~Ai로 j-Ai원 만든 후 Ai원 동전 사용
    // i번째 동전 사용하는 경우와 사용하지 않는 경우로 나눔
    // D[i][j] = D[i-1][j] + D[i][j-Ai] <- 이전 결과에서 하나 더 쓰는 경우
    D[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++) 
        {
            if (j - coins[i] >= 0) // 동전 사용하는 경우
                D[j] += D[j - coins[i]];
        }
    }

    //for (int i = 0; i <= n; i++)
    //{
    //    for (int j = 0; j <= k; j++)
    //    {
    //        cout << D[i][j] << " ";
    //    }
    //    cout << "\n";
    //}

    cout << D[k];

    return 0;
}