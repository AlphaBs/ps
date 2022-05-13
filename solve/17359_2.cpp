#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

string strs[11];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
        for (int j = 1; j < strs[i].size(); j++)
        {
            if (strs[i][j - 1] != strs[i][j])
                sum++;
        }
    }

    int min = INT32_MAX;
    do
    {
        int count = 0;
        for (int i = 1; i < n; i++) // 공집합의 합은 계산할 수 없음
        {
            if (strs[i - 1].back() != strs[i].front())
                count++;
        }

        if (min > count)
            min = count;
    } while (next_permutation(strs, strs + n));
    
    cout << (min + sum);
    return 0;
}