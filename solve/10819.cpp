#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10];

void permutation()
{

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int max = -1;
    do 
    {
        int now = 0;
        for (int i = 1; i < n; i++)
        {
            now += abs(arr[i - 1] - arr[i]);
        }
        if (max < now)
            max = now;
    } 
    while (next_permutation(arr, arr + n));

    cout << max;

    return 0;
}