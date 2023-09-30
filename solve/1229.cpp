// https://www.acmicpc.net/problem/1229

#include <iostream>
#include <cstdio>
#include <algorithm>

#define SIXNUMBERS 710

using namespace std;

int n; // 1,000,000
int maxSixNumberIndex = 1;
int sixNumbers[SIXNUMBERS];

int getSixNumbers(int i)
{
    if (i == 1)
        return 1;

    int& res = sixNumbers[i];
    if (res == 0)
        res = getSixNumbers(i - 1) + 4*i - 3;
    return res;
}

bool solve(int length, int remain)
{
    if (length == 0)
        return remain == 0;

    for (int i = 1; i <= maxSixNumberIndex; i++)
    {
        int nextRemain = remain - getSixNumbers(i);
        if (nextRemain < 0)
            continue;

        if (solve(length - 1, nextRemain))
            return true;
    }

    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    while (n > getSixNumbers(maxSixNumberIndex)) 
        maxSixNumberIndex++;

    int i = 1;
    while (!solve(i, n)) 
        i++;
    cout << i << endl;
    return 0;
}