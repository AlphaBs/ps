// DP

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int nums[1'100'100]; // 1 <= n <= 10^6
int path[1'100'100];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    nums[1] = 0;
    path[1] = -1;
    for (int i = 2; i<=n; i++)
    {
        nums[i] = nums[i - 1] + 1;
        path[i] = i - 1;

        int div2 = nums[i / 2] + 1;
        if (i % 2 == 0 && nums[i] > div2)
        {
            nums[i] = div2;
            path[i] = i / 2;
        }
        int div3 = nums[i / 3] + 1;
        if (i % 3 == 0 && nums[i] > div3)
        {
            nums[i] = div3;
            path[i] = i / 3;
        }

        //cout << i << " " << nums[i] << " " << path[i] << "\n";
    }

    cout << nums[n] << "\n";
    for (int i = n; i != -1; i = path[i])
    {
        cout << i << " ";
    }

    return 0;
}