#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int order[10];
int prices[10];
int discounts[10][10]; 
// discounts[i][j]: i포션을 구매한 경우 j포션이 할인되는 금액

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        order[i] = i;
        cin >> prices[i];
    }

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            int a, b;
            cin >> a >> b;
            discounts[i][a-1] = b;
        }
    }

    int minPrice = INT32_MAX;
    int tempPrices[10];
    do 
    {
        copy(prices, prices + n, tempPrices);
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            int nextPortion = order[i];
            sum += tempPrices[nextPortion];

            for (int j = 0; j < n; j++)
            {
                tempPrices[j] -= discounts[nextPortion][j];
                if (tempPrices[j] <= 0)
                    tempPrices[j] = 1;
            }
        }

        if (minPrice > sum)
            minPrice = sum;
    } while (next_permutation(order, order + n));

    cout << minPrice;
    return 0;
}