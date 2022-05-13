#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool check(int n, int* nums)
{
    bool valid = true;
    for (int i = 0; i < n; i++)
    {
        bool nextValid = true;
        bool prevValid = true;
        int value = nums[i];

        int nextIndex = i + value + 1;
        int prevIndex = i - value - 1;
        if (nextIndex >= n || nums[i] != nums[nextIndex])
        {
            nextValid = false;
        }
        if (prevIndex < 0 || nums[i] != nums[prevIndex])
        {
            prevValid = false;
        }

        if (!nextValid && !prevValid)
        {
            valid = false;
            break;
        }
    }

    return valid;
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
    for (int i = 0; i < 13; i++)
    {
        nums[i*2] = i+1;
        nums[i*2+1] = i+1;
    }

    int count = 0;
    do
    {
        if (nums[x-1] != nums[y-1])
            continue;

        if (check(n*2, nums))
        {
            //for (int k = 0; k < n*2; k++)
            //    cout << nums[k];
            //cout << "\n";
            count++;
        }
    } while (next_permutation(nums, nums + n*2));
    
    cout << count;
    return 0;
}