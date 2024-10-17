// https://www.acmicpc.net/problem/11004
// k'th smallest number
// time complexity: O(n) with randomly chosen pivots, O(n^2) at worst case
// space complexity: O(1)

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

ll n, k;
ll arr[5'555'555];

ll selectPivot(ll start, ll end)
{
    return rand() % end + start;
}

// O(start~end), O(n)
ll partition(ll start, ll end, ll pivotIndex)
{
    ll pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[end]);
    ll storeIndex = start;
    for (ll i = start; i < end; i++)
    {
        if (arr[i] < pivotValue)
        {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[end]);
    return storeIndex;
}

ll quickselect(ll start, ll end, ll k)
{
    while (start <= end)
    {
        ll pivotIndex = selectPivot(start, end);
        pivotIndex = partition(start, end, pivotIndex);

        if (k == pivotIndex)
            return arr[k];
        else if (k < pivotIndex)
            end = pivotIndex - 1;
        else
            start = pivotIndex + 1;
    }
}

int main()
{
    srand(time(nullptr));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    cout << quickselect(0, n - 1, k - 1);
    return 0;
}