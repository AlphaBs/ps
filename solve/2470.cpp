#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
int items[100'000];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }
    sort(items, items + n);

    int left = 0;
    int right = n - 1;

    int minMixed = INT32_MAX;
    int resultLeft = left;
    int resultRight = right;

    while (left < right)
    {
        int mixed = items[left] + items[right];
        if (abs(mixed) < minMixed)
        {
            minMixed = abs(mixed);
            resultLeft = items[left];
            resultRight = items[right];
        }

        if (mixed > 0)
            right--;
        else if (mixed < 0)
            left++;
        else
            break;
    }
    
    cout << resultLeft << " " << resultRight;
    return 0;
}