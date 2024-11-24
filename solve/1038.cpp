// https://www.acmicpc.net/problem/1038

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int fullLength;
int n, th;
char buffer[22];

void enumerateNumber(int start, int length)
{
    if (length == 1)
    {
        buffer[0] = start;
        th++;

        if (n == th)
        {
            for (int i = fullLength - 1; i >= 0; i--)
                cout << (int)buffer[i];
        }
        return;
    }

    buffer[length - 1] = start;
    for (int i = 0; i < start; i++)
    {
        enumerateNumber(i, length - 1);
    }
}

void enumerateNumber(int length)
{
    fullLength = length;
    for (int i = 1; i <= 9; i++)
    {
        enumerateNumber(i, length);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
    }
    else if (n > 1022)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 1; i <= 10; i++)
        {
            enumerateNumber(i);
        }
    }

    return 0;
}