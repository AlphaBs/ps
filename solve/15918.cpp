#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int func(int index, int n, int* nums)
{
    if (nums[index] != 0)
        return 0;

    for (int i = 1; i <= n; i++)
    {
        int nextIndex = index + i + 1;
        
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //int t[10] = {1,2,2,3,1,3};
    //int t[10] = {3,1,2,1,3,2};
    //cout << check(6, t);

    int n, x, y;
    cin >> n >> x >> y;

    int nums[30];
    int fix = y - x - 1;
    nums[x] = fix;
    nums[y] = fix;

    cout << func(0, n, nums);
    return 0;
}