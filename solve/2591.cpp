// https://www.acmicpc.net/problem/2591

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

string line;

int solve(int startIndex)
{
    if (line[startIndex] == '0')
        return 0;

    int remainCharacters = line.length() - startIndex;
    if (remainCharacters == 0)
    {
        return 1;
    }
    else if (remainCharacters == 1)
    {
        int n = line[startIndex] - '0';
        if (n == 0)
            return 0;
        else
            return 1;
    }
    else if (remainCharacters >= 2)
    {
        int count = 0;
        int left = line[startIndex] - '0';
        int right = line[startIndex + 1] - '0';
        int n = left * 10 + right;

        if (left != 0 && right != 0)
            count += solve(startIndex + 1);
        if (1 <= n && n <= 34)
            count += solve(startIndex + 2);

        //cout << startIndex << ',' << count << '\n';
        return count;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> line;
    if (line.length() > 0)
        cout << solve(0);
    else
        cout << '0';
    return 0;
}