// DP

#include <iostream>
#include <cstdio>
#include <algorithm>

#define REVERSE

using namespace std;

int coins[111]; // 1-based index
int D[2][100'100];

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
    for (int i = 1; i <= n; i++) 
    {
        cin >> coins[i];
    }

    sort(coins, coins + n);

    for (int j = 1; j <= k; j++) D[0][j] = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool isSet = false;
            for (int c = 0; c <= j/coins[i]; c++)
            {
                if (j % coins[i] == 0)
                {
                    D[i%2][j] = c;
                    isSet = true;
                }
                else
                {
                    int base = D[(i-1)%2][j-c*coins[i]];
                    if (base == -1)
                        continue;
                    int newValue = base + c;
                    if (D[i%2][j] == 0 || D[i%2][j] > newValue)
                        D[i%2][j] = newValue;
                    isSet = true;
                }
            }
            if (!isSet)
                D[i%2][j] = -1;
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

    cout << D[n%2][k];

    return 0;
}