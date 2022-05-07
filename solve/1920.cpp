#include "iostream"
#include "cstdio"
#include "algorithm"

using namespace std;

int nums[100'000];

bool bsearch(int target, int size)
{
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (target < nums[mid])
            right = mid - 1;
        else if (target > nums[mid])
            left = mid + 1;
        else
            return true;
    }
    return false;
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
        cin >> nums[i];
    }

    sort(nums, nums + n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;
        if (bsearch(target, n))
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}